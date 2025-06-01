

public class Solution {
    public int integerBreak(int n) {
        int[] dp = new int[n + 1];
        for (int i = 2; i <= n; i++) {

            for (int j = 1; j < i; j++) {
                dp[i] = Math.max(dp[i], Math.max(j * (i - j), j * dp[i - j]));
            }

        }
        return dp[n];
    }

    public int integerBreakOpt(int n){
        int[] dp = new int[n+1];
        dp[0] = dp[1] = 0;
        dp[2] = 1;
        for (int i = 3 ; i < n + 1 ; i++){
            for (int j = 1 ; j < i ; j++){
                dp[i] = Math.max(j * (i - j), j * dp[i - j]);
            }
        }

        return dp[n];
    }
}
