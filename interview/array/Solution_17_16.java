public class Solution_17_16 {
    public static void main(String[] args){
        Solution_17_16 solution = new Solution_17_16();
        
        int[] test = {2, 1, 4, 5, 3, 1, 1, 3};
        System.out.println("Max sum: " + solution.message(test));
    }

    public int message(int[] nums){
        if (nums.length == 0) return 0;
        else if (nums.length == 1) return nums[0];

        int[] dp = new int[nums.length];
        
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        
        System.out.println("Initial dp array:");
        System.out.print(dp[0] + " " + dp[1] + " ");
        
        for (int i = 2; i < nums.length; i++){
            dp[i] = Math.max(dp[i-2] + nums[i], dp[i-1]);
            System.out.print(dp[i] + " ");
        }
        
        System.out.println("\nFinal dp array:");
        for (int val : dp){
            System.out.print(val + " ");
        }
        System.out.println();
        
        return dp[nums.length-1];
    }
}
