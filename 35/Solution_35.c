#include <stdio.h>

int binarySearch(int* num , int numsize ,int target){
    int left = 0 , right = numsize - 1;
    while ( left <= right ){
        int mid = left + (( right - left ) >> 1 );
        
        if (num[mid] < target){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main(){
    int array[] = {1,2,5,6,7,22,33,55,66,88,777};
    int arraysize = sizeof(array) / sizeof(array[0]);
    int target;

    printf("请输入你的目标值:");
    scanf("%d",&target);

    int result  = binarySearch(array,arraysize,target);
    printf("目标值应插入的位置索引为: %d\n", result);
    return 0;
}
