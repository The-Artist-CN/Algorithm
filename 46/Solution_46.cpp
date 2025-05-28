

#include <vector>
#include <utility>  // for std::swap

class Solution_46 {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        if (nums.empty()) return result;  
        
        backtrack(nums, 0, result);
        
        return result;
    }

private:
    void backtrack(std::vector<int>& nums, int first, std::vector<std::vector<int>>& result) {
        // 当所有位置都已填完，将当前排列加入结果
        if (first == nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        
        // 尝试将每个数字放到当前位置first上
        for (int i = first; i < nums.size(); ++i) {
            // 交换当前位置和i位置的数字
            std::swap(nums[first], nums[i]);
            // 递归处理下一个位置
            backtrack(nums, first + 1, result);
            // 回溯，撤销交换
            std::swap(nums[first], nums[i]);
        }
    }
};
