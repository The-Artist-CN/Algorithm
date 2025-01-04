import java.util.Arrays;

public class Solution_1672 {
    public int maxWealthCount(int[][] accounts){
        int maxWealth = Integer.MIN_VALUE;
        for (int[] account : accounts){
            maxWealth = Math.max(maxWealth , Arrays.stream(account).sum()); 
        }
        return maxWealth;
    }

    public static void main(String[] args){
        int[][] acc= {{1,3,4},{2,4,5},{2,5,3}};

        Solution_1672 solu = new Solution_1672();

        int result = solu.maxWealthCount(acc);

        System.out.println("result = " + result );
    }
}
        
