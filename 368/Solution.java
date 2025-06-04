import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums); // 排序是关键
        
        // dp[i] 表示以 nums[i] 结尾的最大子集大小
        int[] dp = new int[n];
        Arrays.fill(dp, 1); // 初始化为 1（每个元素自己就是一个子集）
        
        // prev[i] 记录 nums[i] 的前驱节点索引
        int[] prev = new int[n];
        Arrays.fill(prev, -1); // -1 表示无前驱
        
        int maxSize = 1, maxIndex = 0; // 记录最大子集的信息
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j; // 记录前驱
                }
            }
            // 更新全局最大值
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }
        
        // 通过 prev 数组回溯构建结果
        List<Integer> result = new ArrayList<>();
        while (maxIndex != -1) {
            result.add(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }
        Collections.reverse(result); // 需要反转，因为是从后往前添加的
        return result;
    }
}