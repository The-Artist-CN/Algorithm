public class Solution_8 {

    public static void main(String[] args) {
        Solution_8 solution = new Solution_8();
        String s = "   -42";
        System.out.println(solution.myAtoi(s)); // Output: -42
        s = "4193 with words";
        System.out.println(solution.myAtoi(s)); // Output: 4193
    }
    public int myAtoi(String s) {
        char[] c = s.trim().toCharArray();
        if (c.length == 0)
            return 0;
        int res = 0, bndry = Integer.MAX_VALUE / 10;
        int i = 1, sign = 1;
        if (c[0] == '-')
            sign = -1;
        else if (c[0] != '+')
            i = 0;
        for (int j = i; j < c.length; j++) {
            if (c[j] < '0' || c[j] > '9')
                break;
            if (res > bndry || res == bndry && c[j] > '7')
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            res = res * 10 + (c[j] - '0');
        }
        return sign * res;
    }
}
