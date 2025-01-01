import java.text.SimpleDateFormat;
import java.util.Date;

public class Solution {

    private String binary(int x) {
        StringBuilder s = new StringBuilder();
        for (; x != 0; x >>= 1) {
            s.append(x & 1);
        }
        return s.reverse().toString();
    }

    public String convertDateToBinary(String date) {
        int year = Integer.parseInt(date.substring(0, 4));
        int month = Integer.parseInt(date.substring(5, 7));
        int day = Integer.parseInt(date.substring(8, 10));
        return binary(year) + "-" + binary(month) + "-" + binary(day);
    }

    public static void main(String[] args) {
        // 获取当前日期
        Date today = new Date();

        // 将日期转换为字符串格式 YYYY-MM-DD
        SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd");
        String formattedDate = formatter.format(today);

        // 调用 convertDateToBinary 方法
        Solution solution = new Solution();
        System.out.println(solution.convertDateToBinary(formattedDate));
    }
}

