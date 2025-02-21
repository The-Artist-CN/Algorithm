#include <iostream>
#include <vector>

using namespace std;

vector<int> two_number_sum(vector<int>& nums , int target){
   for ( int i = 0 ; i < nums.size() ; i++){
        for( int j = i ; j < nums.size() ; j++){
            if (nums[i] + nums[j] == target){
                return {i,j};
            }
        }
   }
   return {};
}

int main(){
    vector<int> nums = {2,4,5,6,7,8,9,22,44};
    int target = 17;
    vector<int> result = two_number_sum(nums,target);

    if (!result.empty()){
        cout << "Result = " << result[0] << "and" << result[1] << endl;
        } else {
            cout << "Sorry no Found " << endl;
        }

    return 0;

}
