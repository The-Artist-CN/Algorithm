#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int m = nums.size();
        int index = 0;
        for (int i = 0; i < m; ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[index]);
                ++index;
            }
        }
    }
};
