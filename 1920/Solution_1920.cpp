#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> buildArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n); // 创建新数组
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[nums[i]]; // 按要求构建新数组
        }
        return ans;
    }

    std::vector<int> buildArrayV2(std::vector<int>& nums) {
        int n = nums.size();

        // 第一步：计算最终值并存储在 nums 中
        for (int i = 0; i < n; ++i) {
            nums[i] += (nums[nums[i]] % n) * n; // 存储最终值
        }

        // 第二步：提取最终值
        for (int i = 0; i < n; ++i) {
            nums[i] /= n; // 获取最终值
        }

        return nums; // 返回修改后的原数组
    }
};

int main() {
    Solution ss;
    std::vector<int> nums = { 2, 4, 3, 4, 4, 4, 4, 4, 4, 4 };

    // 使用 buildArrayV2 方法
    std::vector<int> resultV2 = ss.buildArrayV2(nums);
    std::cout << "buildArrayV2 result: ";
    for (int val : resultV2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 使用 buildArray 方法
    std::vector<int> nums2 = { 2, 4, 3, 4, 4, 4, 4, 4, 4, 4 }; // 重新初始化 nums
    std::vector<int> result = ss.buildArray(nums2);
    std::cout << "buildArray result: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

