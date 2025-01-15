public class Solution_67 {
    // 核心方法：二进制字符串相加
    public String addBinary(String a, String b) {
        StringBuilder result = new StringBuilder();
        int carry = 0; // 进位
        int i = a.length() - 1;
        int j = b.length() - 1;

        // 从低位开始逐位相加
        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a.charAt(i) - '0'; // 将字符转换为数字
                i--;
            }

            if (j >= 0) {
                sum += b.charAt(j) - '0'; // 将字符转换为数字
                j--;
            }

            result.append(sum % 2); // 当前位
            carry = sum / 2;        // 更新进位
        }

        return result.reverse().toString(); // 返回反转后的结果
    }

    // 测试代码：在主方法中调用
    public static void main(String[] args) {
        Solution_67 solution = new Solution_67();

        // 测试用例
        System.out.println(solution.addBinary("1010", "1011")); // 输出: "10101"
        System.out.println(solution.addBinary("0", "0"));       // 输出: "0"
        System.out.println(solution.addBinary("111", "1"));     // 输出: "1000"

        // 测试超长字符串
        String a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
        String b = "1101010010111011100011110100111010100011110110111010110110000101011011001111100110110111111010111010111";
        System.out.println(solution.addBinary(a, b));
    }
}

