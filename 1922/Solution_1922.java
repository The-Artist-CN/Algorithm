public class Solution_1922 {
    private static final int MOD = 1_000_000_007;

    public static int countGoodNumbers(int n) {
        long evenCount = (n + 1) / 2; // 偶数下标的数量
        long primeCount = n / 2;      // 奇数下标的数量

        long evenOptions = 5; // 偶数下标可选数字数量
        long primeOptions = 4; // 奇数下标可选数字数量

        long evenTotal = power(evenOptions, evenCount, MOD);
        long primeTotal = power(primeOptions, primeCount, MOD);

        return (int) (evenTotal * primeTotal % MOD);
    }

    private static long power(long base, long exp, int mod) {
        long result = 1;
        while (exp > 0) {
            if ((exp % 2) == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    public static void main(String[] args) {
        int n1 = 1;
        int n2 = 4;
        System.out.println("n = " + n1 + ", result = " + countGoodNumbers(n1)); // 输出: 5
        System.out.println("n = " + n2 + ", result = " + countGoodNumbers(n2)); // 输出: 400
    }
}

