public class Solution {
    public static boolean isPalindrome(int x) {
        // 负数或以0结尾但不为0的数都不是回文数
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        
        // 如果数字是回文数，则 x == reversedHalf 或 x == reversedHalf / 10
        return x == reversedHalf || x == reversedHalf / 10;
    }

    public static void main(String[] args) {
        System.out.println(isPalindrome(121));  // 输出: true
        System.out.println(isPalindrome(-121)); // 输出: false
        System.out.println(isPalindrome(10));   // 输出: false
    }
}

