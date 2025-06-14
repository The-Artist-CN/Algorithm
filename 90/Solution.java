

public class Solution {

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<>();
        helper(result,nums,0,path);
        return result;
    }

    public void helper(List<List<Integer>> result , int[] nums,int cur,List<Integer> path){
        if (cur == nums.length){
            result.add(new ArrayList<>(path));
            return;
        }
        path.add(nums[cur]);
        helper(result,nums,cur+1,path);
        path.remove(path.size() - 1);
        while (cur + 1 < nums.length && nums[cur+1] == nums[cur]){
            cur++;
        }
        helper(result,nums,cur+1,path);
    }
}
