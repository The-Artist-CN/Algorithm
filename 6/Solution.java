import java.util.ArrayList;
import java.util.List;

public class Solution {

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "PAYPALISHIRING";
        int numRows = 3;
        String result = solution.convert(s, numRows);
        System.out.println(result); // Output: "PAHNAPLSIIGYIR"
    }
    public String convert(String s, int numRows) {
        if (numRows < 2) return s;
        List<StringBuilder> rows = new ArrayList<StringBuilder>();
        for (int i = 0 ; i < numRows ; i++) rows.add(new StringBuilder());
        int i = 0 , flag = -1;
        for (char c : s.toCharArray()){
            rows.get(i).append(c);
            if (i == 0 || i == numRows - 1) flag = -flag;
            i += flag;
        }
        StringBuilder res = new StringBuilder();
        for (StringBuilder row : rows) res.append(row);
        return res.toString();
    }
}
