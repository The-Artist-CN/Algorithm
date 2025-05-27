import java.util.ArrayList;
import java.util.List;

public class Solution_500 {
    
    public String[] findWords(String[] words) {
        // 预定义键盘各行字符
        String row1 = "qwertyuiopQWERTYUIOP";
        String row2 = "asdfghjklASDFGHJKL";
        String row3 = "zxcvbnmZXCVBNM";
        
        List<String> result = new ArrayList<>();
        
        for (String word : words) {
            if (word.isEmpty()) {
                continue;
            }
            
            // 确定单词所属键盘行
            int row = 0;
            if (row1.indexOf(word.charAt(0)) != -1) {
                row = 1;
            } else if (row2.indexOf(word.charAt(0)) != -1) {
                row = 2;
            } else {
                row = 3;
            }
            
            boolean valid = true;
            for (int i = 1; i < word.length(); i++) {
                char c = word.charAt(i);
                boolean inRow = false;
                
                switch (row) {
                    case 1: inRow = row1.indexOf(c) != -1; break;
                    case 2: inRow = row2.indexOf(c) != -1; break;
                    case 3: inRow = row3.indexOf(c) != -1; break;
                }
                
                if (!inRow) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                result.add(word);
            }
        }
        
        return result.toArray(new String[0]);
    }
}