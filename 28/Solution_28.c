#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strlen
#include <stdbool.h>


int strStr(char* haystack, char* needle) {
    int n = strlen(haystack), m = strlen(needle);
    for (int i = 0; i + m <= n; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) { // Fixed: Increment j instead of i
            if (haystack[i + j] != needle[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}

int main() {
    char* h = "sadbutsad";
    char* n = "sad"; // Fixed: Correctly defined needle as a string
    int result = strStr(h, n);
    printf("%d\n", result); // Fixed: Use the correct format specifier for an integer
    return 0;
}

