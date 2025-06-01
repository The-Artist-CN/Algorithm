
public class Solution {
    public int maxProduct(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        
        int result = nums[0];
        int maxProduct = nums[0];
        int minProduct = nums[0];
        
        for (int i = 1; i < nums.length; i++) {
            // 当遇到负数时，最大值和最小值会互换
            if (nums[i] < 0) {
                int temp = maxProduct;
                maxProduct = minProduct;
                minProduct = temp;
            }
            
            // 更新最大值和最小值
            maxProduct = Math.max(nums[i], nums[i] * maxProduct);
            minProduct = Math.min(nums[i], nums[i] * minProduct);
            
            // 更新全局最大值
            result = Math.max(result, maxProduct);
        }
        
        return result;
    }
}