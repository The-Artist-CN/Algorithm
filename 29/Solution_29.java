public class Solution_29 {
    public int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        
        // Handle edge cases
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;
        
        // Determine the sign of the result
        boolean negative = (dividend < 0) ^ (divisor < 0);
        
        // Work with absolute values (use long to handle Integer.MIN_VALUE)
        long absDividend = Math.abs((long) dividend);
        long absDivisor = Math.abs((long) divisor);
        
        int result = 0;
        
        while (absDividend >= absDivisor) {
            long tempDivisor = absDivisor;
            int multiple = 1;
            
            // Find the largest multiple of divisor <= dividend
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            
            absDividend -= tempDivisor;
            result += multiple;
        }
        
        return negative ? -result : result;
    }
}