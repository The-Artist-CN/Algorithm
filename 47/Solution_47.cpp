#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        sort(nums.begin(), nums.end()); // 先排序，方便去重
        backtrack(nums, 0, result);
        return result;
    }
    
private:
    void backtrack(std::vector<int> nums, int start, std::vector<std::vector<int>>& result) {
        if (start == nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == nums[start]) {
                continue; // 跳过重复元素
            }
            std::swap(nums[start], nums[i]);
            backtrack(nums, start + 1, result);
            // 注意这里不需要swap回来，因为我们传递的是nums的副本
        }
    }
};

void printResult(const std::vector<std::vector<int>>& result) {
    std::cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j];
            if (j != result[i].size() - 1) std::cout << ",";
        }
        std::cout << "]";
        if (i != result.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main(){
    Solution sol;
    std::vector<int> target = {1,2,3};
    std::vector<std::vector<int>> res = sol.permuteUnique(target);
    printResult(res);
    return 0;
}