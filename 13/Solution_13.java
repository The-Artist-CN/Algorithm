import java.util.HashMap;
import java.util.Map;

public class Solution_13 {

    Map<Character, Integer> mm = new HashMap<>();
    {
        mm.put('I', 1);
        mm.put('V', 5);
        mm.put('X', 10);
        mm.put('L', 50);
        mm.put('C', 100);
        mm.put('D', 500);
        mm.put('M', 1000);
    };

    // 罗马数字转整数方法
    int romanToInt(String s) {
        int len = s.length();
        int result = 0; // 初始化结果变量

        for (int i = 0; i < len; i++) {
            int value = mm.get(s.charAt(i));

            // 判断当前字符是否小于下一个字符
            if (i < len - 1 && value < mm.get(s.charAt(i + 1))) {
                result -= value;
            } else {
                result += value;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Solution_13 solution = new Solution_13();
        // 测试样例
        System.out.println(solution.romanToInt("III")); // 输出 3
        System.out.println(solution.romanToInt("IV"));  // 输出 4
        System.out.println(solution.romanToInt("IX"));  // 输出 9
        System.out.println(solution.romanToInt("LVIII")); // 输出 58
        System.out.println(solution.romanToInt("MCMXCIV")); // 输出 1994
    }
}

