#include <stdio.h>

void moveZero(int* nums , int numsSize){
    int ind = 0;

    for (int i = 0 ; i < numsSize ; i++){
        if (nums[i] != 0){
            nums[ind] = nums[i];
            ind++;
        }
    }

    for (int i = ind ; i < numsSize ; i++){
        nums[i] = 0;
    }

}


int main(){
    int nums[] = {1,2,0,0,4,5,6,0};
    size_t numsSize = sizeof(nums) / sizeof (nums[0]);

    moveZero(nums,numsSize);

    for ( size_t i = 0 ; i < numsSize ; i++ ){
        printf("%d ",nums[i]);
    }
    
    return 0;
}
