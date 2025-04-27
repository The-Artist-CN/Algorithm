#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        
        // dp[i] 表示：以 nums[i] 结尾的连续子数组的最大和
        vector<int> dp(len);
        dp[0] = nums[0];
        
        for (int i = 1; i < len; i++) {
            if (dp[i - 1] > 0) {
                dp[i] = dp[i - 1] + nums[i];
            } else {
                dp[i] = nums[i];
            }
        }
        
        // 找出dp数组中的最大值
        int res = dp[0];
        for (int i = 1; i < len; i++) {
            res = max(res, dp[i]);
        }
        
        return res;
    }
    
    int maxSubArrayV2(vector<int>& nums) {
        if (nums.empty()) return 0; // 处理空数组
        int res = nums[0]; // 初始化结果为第一个元素
        int cur = nums[0]; // 当前子数组和初始化为第一个元素
        for (int i = 1; i < nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]); // 选择是否抛弃之前的子数组
            res = max(res, cur); // 更新全局最大值
        }
        return res;
    }
};

// 测试代码
int main() {
    Solution solution;
    
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    cout << solution.maxSubArray(nums1) << endl; // 输出 6
    
    vector<int> nums2 = {1};
    cout << solution.maxSubArray(nums2) << endl; // 输出 1
    
    vector<int> nums3 = {5,4,-1,7,8};
    cout << solution.maxSubArray(nums3) << endl; // 输出 23
    
    vector<int> nums4 = {-1,-2,-3};
    cout << solution.maxSubArray(nums4) << endl; // 输出 -1
    
    return 0;
}
