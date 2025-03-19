#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getRow(int number){
        vector<int> dp( number + 1 , 1 );
        for (int i = 1; i <= number; ++i) {
            for (int j = i - 1; j > 0; --j) {
                dp[j] += dp[j - 1];
            }
        }

        return dp;
    }
};


int main(){
    Solution solution;
    int n;
    cin >> n;
    vector<int> result = solution.getRow(n);
    for ( int r : result ){
        cout << r << " ";
    }

    
    return 0;
}
