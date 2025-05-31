

public class Solution_96 {


    public int numTrees(int n) {
        if (n == 0) return 1; // 空树也算一种情况
        return numTrees(1, n);
    }
    
    private int numTrees(int start, int end) {
        if (start > end) {
            return 1; // 空子树
        }
        
        int total = 0;
        for (int i = start; i <= end; i++) {
            int left = numTrees(start, i - 1);  // 左子树数量
            int right = numTrees(i + 1, end);   // 右子树数量
            total += left * right;  // 左右组合数量是乘积关系
        }
        return total;
    }

    public int numTreesDp(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1; // 空树
        dp[1] = 1; // 只有一个节点
    
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }

}
