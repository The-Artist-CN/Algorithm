class Solution {
    public int fib(int n) {
        final int MOD = 1000000007;
        if (n < 2) return n;
        int pp = 0, p = 1, c = 0;
        for (int i = 2; i <= n; i++) {
            c = (pp + p) % MOD;
            pp = p;
            p = c;
        }
        return c;
    }
}
