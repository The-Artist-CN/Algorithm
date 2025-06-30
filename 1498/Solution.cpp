class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        const int mod = 1e9 + 7;
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1 ; i < n ; i++){
            dp[i] = (dp[i-1] * 2) % mod;
        }
        int left = 0 , right = n - 1;
        int ans = 0;
        while (left <= right){
            if (nums[left] + nums[right] > target){
                right--;
            } else {
                ans = (ans + dp[right-left] ) % mod;
                left++;
            }
        }

        return  ans;

    }
};