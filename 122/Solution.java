
public class Solution {
    
    public int maxProfit(int[] prices){
        int ans = 0;
        int size = prices.length;
        for (int i = 1 ; i < size ; i++){
            ans += Math.max(prices[i] - prices[i-1] , 0);
        }

        return ans;
    }
}