import java.util.Arrays;



public class Solution {
  
  public int[] twoSum(int[] nums , int target){
    int length = nums.length;
    for (int i = 0 ; i < length ; i++){
      for (int j = i+1 ; j < length ; j++ ){
        if (nums[i] + nums[j] == target){
          return new int[]{i,j};  
        }
      }
    }

    return new int[0];
  }




  public static void main(String[] args){
    int[] nums = {1,3,4,5,6};
    int target = 7;
    Solution solution = new Solution();
    System.out.println(Arrays.toString(solution.twoSum(nums , target)));
  }
}
