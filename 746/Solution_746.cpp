#include <vector>
#include <iostream>



class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,0);
        for (int i = 2 ; i < n + 1 ; i++){
            dp[i] = std::min(dp[i-1] + cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }

    int minCostClimbingStairsWithoutDP(std::vector<int>& cost){
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return 1;

        int prev_prev = 0;
        int prev = 0;
        int current ;

        for (int i = 2 ; i <= n ; i++){
            current = std::min(prev+cost[i-1]+prev_prev+cost[i-2]);
            prev_prev = prev;
            prev = current;
        }

        return prev;

    }
};
