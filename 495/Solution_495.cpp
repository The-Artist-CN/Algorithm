#include <vector>

class Solution_495 {
public:
    int findPoisenedDuration(std::vector<int>& nums , int duration){
        int res = 0;
        for (int i = 1; i < nums.size(); i++){
            res += std::min(nums[i] - nums[i-1] , duration);
        }
        return res + duration;
        
    }
}