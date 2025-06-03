
public class Solution {

    public int numberOfArithmeticSlices(int[] nums) {
        int l = 0, ans = 0;
        for (int i = 2; i < nums.length; i++) {
            if (nums[i] + nums[i - 2] == nums[i - 1] * 2) {
                ans += ++l;
            } else {
                l = 0;
            }
        }
        return ans;
    }
}