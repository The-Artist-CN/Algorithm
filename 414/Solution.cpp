#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // 先排序（升序）
        sort(nums.begin(), nums.end());
        
        // 去重（保留唯一元素）
        int n = nums.size();
        int uniqueCount = 1; // 至少有一个数
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[uniqueCount++] = nums[i]; // 原地去重
            }
        }
        
        // 如果去重后不足 3 个数，返回最大的数
        if (uniqueCount < 3) {
            return nums[uniqueCount - 1];
        }
        
        // 否则返回第三大的数
        return nums[uniqueCount - 3];
    }
};