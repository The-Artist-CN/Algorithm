#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumberUseBitOr(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i : nums){
            result ^= i;
        }

        for (int i = 0 ; i <= n ; i++){
            result ^= i;
        }

        return result;
    }

    int missingNumberUseHashMap(vector<int>& nums){
        int n = nums.size();
        unordered_set<int> unset;

        for (int i = 0; i < n ; i++){
            unset.insert(nums[i]);
        }
        
        int missing = -1;
        for (int i = 0 ; i <= n ; i++){
            if (!unset.count(i)){
                missing = i;
                break;
            }
        }

        return missing;
    }

    int missingNumberUseMath(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2;
        int arrSum = 0;
        for (int i = 0; i < n; i++) {
            arrSum += nums[i];
        }
        return total - arrSum;
    }

};
