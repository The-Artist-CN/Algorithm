import java.util.HashMap;
import java.util.Arrays;
public class Better_Solution {
    public int[] twoSum(int[] nums , int target){
        HashMap<Integer , Integer> map = new HashMap<>();
        for (int i = 0; i< nums.length ; i++){
            int complement = target - nums[i];
            if ( map.containsKey(complement)){
                return new int[]{map.get(complement),i};
            }
            map.put(nums[i],i);
        }
        return new int[0];
    }

    public static void main(String[] args){
        Better_Solution bs = new Better_Solution();
        int[] nums = {2,7,11,15};
        int target = 9;
        System.out.println(bs.twoSum(nums,target));
        System.out.println(Arrays.toString(bs.twoSum(nums,target)));
    }
}

            
