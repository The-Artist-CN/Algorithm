#include <vector>
#include <iostream>

using namespace std;

class Solution_78 {
    vector<int> t;
    vector<vector<int>> ans;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            t.clear();
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    t.push_back(nums[i]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }

    vector<vector<int>> subsetsRecur(vector<int>& nums){
        subsetsRecur(0,nums);
        return ans;
    }

private:
    void subsetsRecur(int index , vector<int>& nums){

        if (index == nums.size()){
            ans.push_back(t);
        }

        t.push_back(nums[index]);
        subsetsRecur(index+1,nums);
        t.pop_back();
        subsetsRecur(index+1,nums);
        
    }
};



