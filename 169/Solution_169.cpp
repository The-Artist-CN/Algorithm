#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        
        // Populate the hashmap with element frequencies
        for (int i = 0; i < nums.size(); i++) {
            hashmap[nums[i]]++;
        }

        // Find the majority element
        int majority = nums.size() / 2;
        int result = 0;
        for (const auto& e : hashmap) {
            int element = e.first;
            int count = e.second;
            if (count > majority) {
                result = element;
                break;
            }
        }

        return result;
    }
};


int main(){
    Solution solution;
    vector<int> nums = {3, 2, 3};
    cout << "Majority Element: " << solution.majorityElement(nums) << endl;
    return 0;
}
