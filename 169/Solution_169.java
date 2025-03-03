//方法二：排序

import java.util.Arrays;

public class Solution_169 {
    
    public static void main(String[] args){
        Solution solution = new Solution();
        int[] nums = {3, 2, 3};
        System.out.println("多数元素是: " + solution.majorityElement(nums)); // 输出: 3

        int[] nums2 = {2, 2, 1, 1, 1, 2, 2};
        System.out.println("多数元素是: " + solution.majorityElement(nums2)); // 输出: 2
    }
}

class Solution {

    public int majorityElement( int[] nums ){
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }
}
