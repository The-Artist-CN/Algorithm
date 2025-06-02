
public class Solution {

    public int findUnsortedSubarray(int[] nums){

        int right = -1;
        int max = Integer.MIN_VALUE;
        for (int i = 0 ; i < nums.length ; i++){
            if (nums[i] >= max){
                max = nums[i];
            } else {
                right = i; 
            }
        }

        if (right == -1) return 0;

        int left = nums.length;
        int min = Integer.MAX_VALUE;

        for (int i = nums.length - 1 ; i >= 0 ; i--){
            if (nums[i] > min){
                left = i;
            } else {
                min = nums[i];
            }
        }

        return Math.max(right - left + 1 , 0);
    }
}