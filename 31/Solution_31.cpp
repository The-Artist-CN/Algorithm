
#include <vector>
#include <algorithm>

class Solution_46 {
public:
    void nextPermutation(std::vector<int>& nums){
        int n = nums.size();
        int pivot = -1;

        for (int i = n - 2 ; i >= 0 ; --i){
            if (nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        } 

        if (pivot == -1) {
            // The array is in descending order, reverse to get the smallest permutation
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i > pivot; --i) {
            if (nums[i] > nums[pivot]) {
                std::swap(nums[i], nums[pivot]);
                break;
            }
        }

        reverse(nums.begin() + pivot + 1, nums.end());


    }
};


