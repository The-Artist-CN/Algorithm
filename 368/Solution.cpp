class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        
        // 1. 排序数组
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<int> dp(n, 1);  // dp[i] 表示以nums[i]结尾的最大子集大小
        vector<int> prev(n, -1);  // 记录前驱元素索引
        
        int max_len = 1, max_idx = 0;
        
        // 2. 动态规划填充dp数组
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                max_idx = i;
            }
        }
        
        // 3. 回溯构造结果
        vector<int> result;
        for (int i = max_idx; i != -1; i = prev[i]) {
            result.push_back(nums[i]);
        }
        
        return result;
    }
};