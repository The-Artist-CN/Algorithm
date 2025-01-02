#include <iostream> 
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums , int target){
        for ( int i = 0 ;i < nums.size() ; i++)
            for ( int j = i+1; j< nums.size() ; j++){
                if (nums[i] + nums[j] == target){
                    return {i,j};
                };
            };
            return {};

    };
};


int main(){
    vector<int> nums = {1,3,4,5,6,8};
    int target;
    cin >> target;

    Solution solution;
    vector<int> result = solution.twoSum(nums,target);
    if (!result.empty()){
        cout<< "[" << result[0] <<","<<result[1]<<"]" << endl;
    } else {
        cout << "No found" << endl;
    }
    
    return 0;
}