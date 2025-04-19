class Solution {
    public int[] countBits(int n) {
        int[] res = new int[n+1];
        res[0] = 0;
        for(int i = 1; i <= n; i++){
            res[i] = res[i>>1] + i % 2;
        }
        return res;
    }
}
