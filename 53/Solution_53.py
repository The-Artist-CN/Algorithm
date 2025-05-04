
class Solution:
    def maxSubArray( self , nums: list[int] ) -> int :
        size = len(nums);
        if size == 0:
            return 0;
        dp = [0 for i in range(size)];

        dp[0] = nums[0];

        for i in range(size):
            if dp[i-1] > 0:
                dp[i] = dp[i-1] + nums[i];
            else:
                dp[i] = nums[i];

        return max(dp);
    def maxSubArray_Better(self, nums: list[int]) -> int:
        max_sum = current_sum = nums[0]  # 初始化为第一个元素
        for num in nums[1:]:  # 从第二个元素开始遍历
            current_sum = max(num, current_sum + num)  # 决定是否重新开始子数组
            max_sum = max(max_sum, current_sum)  # 更新全局最大值
        return max_sum
