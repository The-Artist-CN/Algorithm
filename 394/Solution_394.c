

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* str;
    int repeat;
} StackItem;

char* decodeString(char* s){
    int len = strlen(s);
    char* res = (char*) malloc(100000 * sizeof(char));
    res[0] = '\0';

    StackItem* stack = (StackItem*) malloc(100 * sizeof(StackItem));

    int top = -1;

    int num = 0;

    char* cur = (char*) malloc(10000 * sizeof(char));

    cur[0] = '\0';

    for (int i = 0 ; i < len ; i++){
        if (isdigit(s[i])){
            num = num * 10 + (s[i] - '0');
        } else if (s[i] == '['){
            stack[++top].str = (char*) malloc(strlen(cur) + 1);
            strcpy(stack[top].str,cur);
            stack[top].repeat = num;
            num = 0;
            cur[0] = '\0';
        } else if (s[i] == ']'){
            char* temp = (char*) malloc(10000 * sizeof(char));
            temp[0] = '\0';
            for (int j = 0; j < stack[top].repeat; j++) {
                strcat(temp,cur);
            }
            strcpy(cur, stack[top].str);
            strcat(cur, temp);
            top--;
            free(temp);
        } else {
            int len = strlen(cur);
            cur[len] = s[i];
            cur[len+1] = '\0';
        }
    }

    free(stack);
    return cur;
}
