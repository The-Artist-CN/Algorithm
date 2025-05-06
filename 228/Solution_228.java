import java.util.ArrayList;
import java.util.List;

public class Solution_228 {
    public static void main(String[] args) {
        // 测试用例
        int[] nums = {0,1,2,4,5,7};
        Solution_228 solution = new Solution_228();
        List<String> result = solution.summaryRanges(nums);
        System.out.println(result); // 应输出: ["0->2", "4->5", "7"]
    }

    public List<String> summaryRanges(int[] nums) {
        List<String> result = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return result;
        }
        
        // 遍历数组
        for (int i = 0; i < nums.length; i++) {
            int start = nums[i];
            // 检查后续元素是否连续
            while (i + 1 < nums.length && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            
            // 根据是否连续决定输出格式
            if (start == nums[i]) {
                result.add(String.valueOf(start)); // 单个数字
            } else {
                result.add(start + "->" + nums[i]); // 连续范围
            }
        }
        
        return result;
    }
}