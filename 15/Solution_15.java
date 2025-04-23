import java.util.*;

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        int n = nums.length;
        
        if (nums == null || n < 3) return list;

        Arrays.sort(nums);  // Fixed: Changed "Array.sort" to "Arrays.sort"

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) { 
                    list.add(Arrays.asList(nums[i], nums[left], nums[right]));  // Fixed: Added elements separately
                    while (left < right && nums[left] == nums[left + 1]) left++;  // Fixed: Changed to left + 1
                    while (left < right && nums[right] == nums[right - 1]) right--;  // Fixed: Changed to right - 1
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return list;  // Added: Missing return statement
    }
}
