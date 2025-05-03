#include <iostream>
#include <vector>
using namespace std;

class Solution_35 {
public:
    int searchInsert ( vector<int>& nums , int target ){
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target){
                return mid;
            } else if (nums[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};

//Mar 3 15:00PM

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] < target){
                left = mid + 1;
            } else if (nums[mid] > target){
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return left;
    }
};

int main(){
    Solution_35 ss;
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    int target = 10;
    int target2 = 1;
    cout << "Output :" << ss.searchInsert(v,target) << endl;
    cout << "Output :" << ss.searchInsert(v,target2) << endl;
    return 0;
}
