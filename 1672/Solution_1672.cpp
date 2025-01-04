#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
class Solution {
    public:
        int maxWealthCount(vector<vector<int>>& accounts){
            int maxWealth = INT_MIN;
            for (const auto& account : accounts){
                int current_Wealth = accumulate(account.begin(),account.end(),0);
                maxWealth = max(maxWealth ,current_Wealth);
            }
            return maxWealth;
        }
};


int main (){
    vector<vector<int>> accounts = {
        {1,3,4},
        {3,5,6},
        {3,6,7}
    };

    Solution solu;

    int result = solu.maxWealthCount(accounts);
    cout << "result = " << result << endl;

    return 0;
}

