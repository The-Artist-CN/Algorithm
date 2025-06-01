import java.util.Arrays;

public class Solution {
    public int coinChange(int[] coins, int target) {
        // 创建一个dp数组，dp[i]表示凑出金额i需要的最少硬币数
        int[] dp = new int[target + 1];
        
        // 初始化为target+1（表示不可达，因为最多需要target个1元硬币）
        Arrays.fill(dp, target + 1);
        
        // 金额0需要0个硬币
        dp[0] = 0;
        
        // 计算从1到target的每个金额
        for (int i = 1; i <= target; i++) {
            // 尝试每种硬币
            for (int coin : coins) {
                // 只有当硬币面额不大于当前金额时才考虑
                if (coin <= i) {
                    // 更新dp[i]为min(当前值, 使用这枚硬币后的结果)
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // 如果dp[target]没有被更新过，说明无法凑出目标金额
        return dp[target] > target ? -1 : dp[target];
    }
}