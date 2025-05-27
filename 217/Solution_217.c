
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a , const void *b){
    return (*(int*)a - *(int*)b); 
}

bool containsDuplicate(int* nums , int numSize){

    if (numSize < 2){
        return false;
    }

    qsort(nums,numSize,sizeof(int) , compare);

    for (int i = 0 ; i < numSize - 1 ; i++){
        if (nums[i+1] == nums[i]){
            return true;
        }
    }
    
    return false;
}

bool containsDuplicateHash(int* nums, int numsSize) {

    int hash[1000] = {0};

    for (int i = 0 ; i < numsSize ; i++){
        if (hash[nums[i]] == 1){
            return true;
        }
        hash[nums[i]] = 1;
    }
    return false;
}