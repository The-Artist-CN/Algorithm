/*
一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。
给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int massage(vector<int>& nums) {
    if (nums.empty()) return 0; // 如果数组为空，返回 0
    if (nums.size() == 1) return nums[0]; // 如果只有一个预约，直接返回

    // 定义两个变量代替 dp 数组
    int prev2 = 0; // dp[i-2]
    int prev1 = 0; // dp[i-1]

    for (int num : nums) {
        // 当前状态
        int current = max(prev1, prev2 + num);
        // 更新状态
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main() {
    // 测试用例
    vector<int> nums1 = {1, 2, 3, 1};
    cout << massage(nums1) << endl; // 输出: 4

    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << massage(nums2) << endl; // 输出: 12

    vector<int> nums3 = {2, 1, 4, 5, 3, 1, 1, 3};
    cout << massage(nums3) << endl; // 输出: 12

    vector<int> nums4 = {};
    cout << massage(nums4) << endl; // 输出: 0

    return 0;
}







