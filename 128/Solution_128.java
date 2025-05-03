
public class Solution_128 {
    public static void main(String[] args){

    }
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;

        Arrays.sort(nums);
        int currentSeq = 1;
        int longestSeq = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i-1]) {  // Skip duplicates
                if (nums[i] == nums[i-1] + 1) {
                    currentSeq++;
                } else {
                    longestSeq = Math.max(longestSeq, currentSeq);
                    currentSeq = 1;
                }
            }
        }

        return Math.max(longestSeq, currentSeq);
    }
    public int longestConsecutive(int[] nums){
        Set<Integer> numSet = new HashSet<>();
        for (int num : nums){
            numSet.add(num);
        }

        int longestSeq = 0;

        for (int num : numSet){
            if (!numSet.contains(num-1)){
                int cur = num;
                int curSeq = 1;
            }

            while (numSet.contains(cur+1)){
                cur++;
                curSeq++;
            }

            longestSeq = Math.max(longestSeq,curSeq);
        }
        
        return longestSeq;

    }
}
