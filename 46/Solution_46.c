#include <stdio.h>
#include <stdlib.h>

// 函数声明（函数原型）
void swap(int *a, int *b);
void backtrack(int *nums, int numsSize, int level, int **result, int *returnSize, int **returnColumnSizes);

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    // Calculate the number of permutations (n!)
    *returnSize = 1;
    for (int i = 1; i <= numsSize; i++)
    {
        *returnSize *= i;
    }

    // Allocate memory for the result array and column sizes
    int **result = (int **)malloc(*returnSize * sizeof(int *));
    *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));
    printf("result 指针地址 = %p\n", (void *)result);
    printf("returnColumnSizes 指针地址 = %p\n", (void *)(*returnColumnSizes));
    for (int i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = numsSize;
        result[i] = (int *)malloc(numsSize * sizeof(int));
    }

    // Generate permutations using backtracking
    backtrack(nums, numsSize, 0, result, returnSize, returnColumnSizes);

    return result;
}

void backtrack(int *nums, int numsSize, int level, int **result, int *returnSize, int **returnColumnSizes)
{
    static int count = 0;

    if (level == numsSize)
    {
        // Copy the current permutation to the result array
        for (int i = 0; i < numsSize; i++)
        {
            result[count][i] = nums[i];
        }
        count++;
        return;
    }

    for (int i = level; i < numsSize; i++)
    {
        // Swap the current element with the element at index 'level'
        swap(&nums[level], &nums[i]);

        // Recursively generate permutations for the next level
        backtrack(nums, numsSize, level + 1, result, returnSize, returnColumnSizes);

        // Backtrack (undo the swap)
        swap(&nums[level], &nums[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Helper function to print the permutations (for testing)
void printPermutations(int **permutations, int size, int numsSize)
{
    for (int i = 0; i < size; i++)
    {
        printf("[");
        for (int j = 0; j < numsSize; j++)
        {
            printf("%d", permutations[i][j]);
            if (j < numsSize - 1)
                printf(", ");
        }
        printf("]\n");
    }
}

// Example usage
int main()
{
    int nums[] = {1, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *returnColumnSizes;

    int **result = permute(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("All permutations:\n");
    printPermutations(result, returnSize, numsSize);

    // Free allocated memory
    for (int i = 0; i < returnSize; i++)
    {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}