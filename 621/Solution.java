import java.util.Arrays;

public class Solution {
    
    public int leastInterval(char[] tasks , int n){
        int[] map = new int[26];

        for (char c : tasks){
            map[c-'A']++;
        }

        Arrays.sort(map);

        int maxNum = map[25];
        int idle = (maxNum - 1) * n;

        for (int i = 0 ; i < 25 ; i++){
            idle -= Math.min(map[i],maxNum - 1);
        }

        idle = Math.max(0,idle);

        return tasks.length + idle;
    }
}