
import java.util.List;
import java.util.ArrayList;
public class Solution_78 {

    private List<Integer> t = new ArrayList<>();

    private List<List<Integer>> result = new ArrayList<List<Integer>>();


    public List<List<Integer>> subsets(int[] nums){
        dfs(0,nums);
        return result;
    }

    void dfs(int cur , int[] nums){
        if (cur == nums.length){
            result.add(new ArrayList<Integer>(t));
            return;
        }
        t.add(nums[cur]);
        dfs(cur+1,nums);
        t.remove(t.size()-1);
        dfs(cur+1,nums);
    }
}