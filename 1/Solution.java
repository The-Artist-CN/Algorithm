import java.util.Arrays;


public class Solution_1 {
  
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

  public int[] twoSum(int[] nums, int target) {
     Map<Integer,Integer> m = new HashMap<Integer,Integer>();
        for (int i = 0 ; i < nums.length ; i++){
            if (m.containsKey(target-nums[i])) return new int[]{m.get(target-nums[i]),i};
            m.put(nums[i] , i);
        }
        return new int[0];
    }
}

