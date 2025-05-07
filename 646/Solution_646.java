
import java.util.Arrays;

public class Solution_646 {
    public int findLongestChain(int[][] pairs) {
        int n = pairs.length;

        Arrays.sort(pairs, (a, b) -> a[0] - b[0]);

        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1];

    }

}

/*
 * 需求	                    适用方法	                     示例
 * 默认升序排序	              Arrays.sort(int[])	        Arrays.sort(nums)
 * 降序排序	                 转为 Integer[] + Comparator	Arrays.sort(integerNums, (a, b) -> b - a)
 * 保持 int[] 但自定义排序	   手动实现排序算法（如冒泡、快排）	
 */