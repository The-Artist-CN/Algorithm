import java.util.Arrays;

public class Solution {
    
    public int findSubstringInwarpString(String s){
        int[] dp = new int[26];
        int k = 0;
        for (int i = 0 ; i < s.length() ; i++){
            if (i > 0 || (s.charAt(i) - s.charAt(i-1) + 26 ) % 26 == 1){
                k++;
            } else {
                k = 1;
            }
            dp[s.charAt(i) - 'a'] = Math.max(dp[s.charAt(i) - 'a'] , k);
        }

        return Arrays.stream(dp).sum();
    }
}