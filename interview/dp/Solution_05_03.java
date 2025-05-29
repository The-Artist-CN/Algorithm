

public class Solution {

    public int reverseBits(int num){

        int res = 1;
        int cur = 0;
        int insert = 0;

        for (int i = 0 ; i < 32 ; i++){
            if ((num & (1 << i)) != 0){
                cur += 1;
                insert += 1;
            } else {
                insert = cur + 1;
                cur = 0
            }

            res = Math.max(res,insert);
        }

        return res;
    }
}
