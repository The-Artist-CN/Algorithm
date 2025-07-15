int thirdMax(int* nums, int numsSize) {
    long third = LONG_MIN , second = LONG_MIN , first = LONG_MIN;
    for (int i = 0 ; i < numsSize ; i++){
        int num = nums[i];
        if (num > first){
            third = second;
            second = first;
            first = num;
        } else if (num < first && num > second){
            third = second;
            second = num;
        } else if (num < second && num > third){
            third = num;
        }
    }
    return third == LONG_MIN ? first : third;
}