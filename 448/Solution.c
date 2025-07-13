int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int *map = calloc(numsSize , sizeof(int));
    for (int i = 0 ; i < numsSize ; i++){
        map[nums[i] - 1] = 1;
    }
    int count = 0;
    for (int j = 0 ; j < numsSize ; j++){
        if(!map[j]){
            count++;
        }
    }
    int *res = malloc(count * sizeof(int));
    for (int index = 0 , j = 0 ; j < numsSize ; j++){
        if (!map[j]){
            res[index++] = j + 1;
        }
    }
    free(map);
    *returnSize = count;
    return res;
}

int* findDisappearedNumbersBetter(int* nums, int numsSize, int* returnSize) {
    // 原地标记：将 nums[i] 对应的索引位置取负
    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1; // 转换为 0-based 索引
        if (nums[index] > 0) {
            nums[index] = -nums[index]; // 标记为负数，表示该数字出现过
        }
    }

    // 统计未被标记的数字（即缺失的数字）
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            count++;
        }
    }

    // 分配返回数组
    int *res = malloc(count * sizeof(int));
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            res[index++] = i + 1; // 缺失的数字是 i + 1
        }
    }

    *returnSize = count;
    return res;
}
