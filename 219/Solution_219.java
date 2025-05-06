import java.util.HashMap;

public class Solution_219 {

    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer> seen = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            if (seen.containsKey(num) && i - seen.get(num) <= k) {
                return true;
            }
            seen.put(num, i);
        }
        return false;
    }
}