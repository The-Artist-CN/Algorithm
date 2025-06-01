#include <vector>
#include <algorithm> // for std::min
#include <climits>   // for INT_MAX

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Initialize dp array with amount+1 (which is essentially infinity for this problem)
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // Base case: 0 coins needed to make amount 0
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
