


class Solution {
public:
    int waysToStep(int n){
        if (n = 0) return 1;
        if (n = 1) return 1;
        if (n = 2) return 2;

        const int MOD = 100000007;
        int a = 1 , b = 2 , c = 3 , d;


        for (int i = 3 ; i < n ; i++){
            d = (a + b + c) % MOD;
            a = b;
            b = c;
            c = d;
        }

        return c;
    }
}
