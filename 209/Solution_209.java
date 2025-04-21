public class Solution_209 {
    public static void main(String[] args) {
        // Example usage
        Solution sol = new Solution();
        int[] nums = {2, 3, 1, 2, 4, 3};
        int target = 7;
        System.out.println(sol.minSubArrayLen(target, nums)); // Output: 2
    }
}

class Solution {
    // Brute-force solution (O(n²) time)
    int minSubArrayLenBruteForce(int[] nums, int target) {
        if (nums == null || nums.length == 0) return 0;
        int ans = Integer.MAX_VALUE;
        
        for (int i = 0; i < nums.length; i++) {
            int sum = 0;
            for (int j = i; j < nums.length; j++) {
                sum += nums[j];
                if (sum >= target) {
                    ans = Math.min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }

    // Optimized sliding window solution (O(n) time)
    public int minSubArrayLen(int target, int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        
        int left = 0, sum = 0;
        int minLen = Integer.MAX_VALUE;
        
        for (int right = 0; right < nums.length; right++) {
            sum += nums[right];
            while (sum >= target) {
                minLen = Math.min(minLen, right - left + 1);
                sum -= nums[left++];
            }
        }
        
        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }
}
