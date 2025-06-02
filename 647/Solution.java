
public class Solution {
    
    public int countSubStrings(String s){
        int ans = 0;

        for (int i = 0 ; i < s.length() ; i++){
            ans += expand(s,i,i) + expand(s,i,i+1);
        }

        return ans;
    }

    private int expand(String target , int left , int right){
        int res = 0;
        while (left >= 0 && right <= target.length() -1 && target.charAt(left) == target.charAt(right)){
            left--;
            right++;
            res++;
        }

        return res;
    }
}