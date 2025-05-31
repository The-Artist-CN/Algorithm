import java.util.Arrays;
import java.util.Random;

public class Solution {

    private final Random rand = new Random();

    public int findKthLargest(int[] nums , int k){
        return quickSelect(nums,k);
    }

    int quickSelect(int[] nums , int k){
        int pivot = nums[rand.nextInt(nums.length)];

        int[] bigger = Arrays.stream(nums).filter(n -> n > pivot).toArray();
        int[] equals = Arrays.stream(nums).filter(n -> n == pivot).toArray();
        int[] smaller = Arrays.stream(nums).filter(n -> n < pivot).toArray();

        if (k <= bigger.length){
            return quickSelect(bigger, k);
        } else if (k > (bigger.length + equals.length)){
            return quickSelect(smaller, k - (bigger.length + equals.length));
        } else {
            return pivot;
        }
    }
}