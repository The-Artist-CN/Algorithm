class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0],nums[1]);
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for (int i = 2 ; i < nums.size() ; i++){
            dp[i] = max(nums[i] + dp[i-2] , dp[i-1]);
        }
        return dp.back();

    }
    
    int rob_better(vector<int>& nums){
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0],nums[1]);
        int prepre = nums[0];
        int pre = max(nums[0],nums[1]);
        int target = 0;
        for (int i = 2 ; i < nums.size() ; i++){
            target = max(nums[i] + prepre , pre);
            prepre = pre;
            pre = target;
        }
        return target;
    }
};
