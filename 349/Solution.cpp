#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1 , vector<int> &nums2){
        vector<int> result;
        unordered_map<int,int> hash;

        for (const auto &num : num1){
            hash[num] = 1;
        }

        for (const auto &num : nums2){
            hash[num]--;
            if (hash[num] == 0){
                result.push_back(num);
            }
        }

        return result;
    }
};