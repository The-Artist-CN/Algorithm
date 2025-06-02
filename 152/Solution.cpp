#include <vector>
#include <algorithm>


class Solution {
public:
    int maxProduct(std::vector<int>& nums){
        if (nums.empty()) return 0;
        int res = nums[0];
        int max = nums[0]; 
        int min = nums[0];
        for (int i = 1 ; i < nums.size() ; i++){
            if (nums[i] < 0){
                swap(max,min);
            }
            max = std::max(nums[i],nums[i] * max);
            min = std::min(nums[i],nums[i] * min);

            res = std::max(res,max);
        }
        return res;
    }
};