#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = max(dp[i + 1], questions[i][0] + dp[min(n, i + questions[i][1] + 1)]);
        }
        return dp[0];
    }
};

int main(){
    vector<vector<int>> example = {{3, 2}, {4, 3}, {5, 2}, {6, 1}};
    Solution sol;
    cout << sol.mostPoints(example) << endl;
    return 0;
}
