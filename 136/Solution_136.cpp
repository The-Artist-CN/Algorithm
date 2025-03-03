#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
*/

class Solution {
public:
    int singleNumber(vector<int>& nums){
        unordered_map<int,int> hashmap;
        for ( int n : nums){
            hashmap[n]++;
        }
        int result;
        for ( int i : nums){
            if ( hashmap[i] == 1){ result = i; };
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {4,2,1,2,4};
    cout << "Result = " << solution.singleNumber(nums) << "" << endl;
    return 0;
}
