#include <iostream>
#include <vector>

int climbStairs(int n){
    if (n <= 2){
        return n;
    }

    std::vector<int> dp(n);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3 ; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main(){
    std::cout << climbStairs(5) << std::endl;
    return 0;
}

