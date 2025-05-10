#include <stdio.h>
#include <math.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

bool canJump(int *nums, int size)
{
    int k = 0;

    for (int i = 0; i < size; i++)
    {
        if (i > k)
        {
            return false;
        }
        k = max(k, i + nums[i]);
    }
    return true; // 添加这行
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);

    bool result = canJump(nums, size);
    printf("%s\n", result ? "true" : "false");

    return 0;
}