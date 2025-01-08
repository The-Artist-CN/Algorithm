import java.util.TreeSet;
import java.util.Set;


public class Solution_26 {

    public static int removeDuplicateNum(int[] nums){
        if (nums != null && nums.length == 0 ){
            return 0;
        }

        int slow = 0;

        for (int fast = 0; fast < nums.length ; fast++){
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }

        }

        return slow + 1;
    }

    //Using TreeSet

    public static int removeDupliNumByTreeSet(int[] nums){
        Set<Integer> treeset = new TreeSet<>();
        for (int num : nums){
            treeset.add(num);
        }
        return treeset.size();
    }

    public static void main(String[] args){
        int[] nums = {1,2,3,3,4,4,4,4,5,5,6,6,6,6,7,7,7,8,8};
        int result = removeDuplicateNum(nums);
        System.out.println("result = " + result);
        System.out.print("修改后的数组：");
        for (int i = 0; i < result ; i++){
            System.out.print("" + nums[i] );
        }

        System.out.println();
        result = removeDupliNumByTreeSet(nums);
        System.out.println(result);
    }
}



