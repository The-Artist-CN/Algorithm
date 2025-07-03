#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int majorityElement(int *nums , int size){
    qsort(nums,size,sizeof(int),compare);
    return nums[size/2];
}

int majorityElementV2(int *nums , int size){
    int winner = nums[0];
    int count = 1;
    for ( int  i = 1; i < size; i++){
        if (winner == nums[i]){
            count++;
        } else if (count == 0){
            winner = nums[i];
            count = 1;
        } else {
            count--;
        }
    }
     
}


int main(){

    int nums1[] = {3, 2, 3};
    int nums2[] = {2, 2, 1, 1, 1, 2, 2};
    
    printf("Majority element in [3, 2, 3]: %d\n", majorityElement(nums1, 3)); // 输出 3
    printf("Majority element in [2, 2, 1, 1, 1, 2, 2]: %d\n", majorityElement(nums2, 7)); // 输出 2
    
    return 0;
}