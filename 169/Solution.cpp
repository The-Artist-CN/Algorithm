#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int target = nums.size() / 2;
        int left = 0;
        for ( int right = 0 ; right < nums.size() ; right++){
            if (nums[right] != nums[left]){
                if (right - left  > target){
                    return nums[left];
                } else {
                    left = right;
                }
            }
        }
        if (nums.size() - left > target) {
            return nums[left];
        }
        return -1;
    }

    int majorityElementByLeetcode(vector<int>& nums){
        sort(nums.begin() , nums.end());
        return nums[nums.size()/2];
    }
};
