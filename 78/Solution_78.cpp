#include <vector>
#include <iostream>

using namespace std;

class Solution_78 {
public:
    vector<int> t;
    vector<vector<int>> ans;

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
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution_78 sol;
    vector<vector<int>> result = sol.subsets(nums);
    
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i != subset.size() - 1) {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
    
    return 0;
}