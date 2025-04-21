import java.util.ArrayList;
import java.util.List;

public class Solution_3 {
    public static void main(String[] args){
        Solution sol = new Solution();
    
        // 1. Empty string
        System.out.println(sol.lengthOfTheLongestSubString("")); // Expected: 0
    
        // 2. All identical characters
        System.out.println(sol.lengthOfTheLongestSubString("aaaaa")); // Expected: 1
    
        // 3. Entire string is unique
        System.out.println(sol.lengthOfTheLongestSubString("abcdefg")); // Expected: 7
    
        // 4. String with spaces
        System.out.println(sol.lengthOfTheLongestSubString("a b c d e")); // Expected: 5
    
        // 5. Mixed case sensitivity
        System.out.println(sol.lengthOfTheLongestSubString("aAabBbcC")); // Expected: 3 (case sensitive)
    
        // 6. Unicode characters
        System.out.println(sol.lengthOfTheLongestSubString("你好世界你好")); // Expected: 4
    
        // 7. Very long string with repeating pattern
        String longStr = "abc".repeat(10000) + "xyz".repeat(10000);
        System.out.println(sol.lengthOfTheLongestSubString(longStr)); // Expected: 3 (from "xyz")
    
        // 8. String with special characters
        System.out.println(sol.lengthOfTheLongestSubString("!@#$%^&*()")); // Expected: 10
    
        // 9. String with numbers
        System.out.println(sol.lengthOfTheLongestSubString("112233445566")); // Expected: 2
    
        // 10. Alternating duplicates
        System.out.println(sol.lengthOfTheLongestSubString("ababababab")); // Expected: 2
    
        // 11. Single character
        System.out.println(sol.lengthOfTheLongestSubString("z")); // Expected: 1
    
        // 12. Newline and control characters
        System.out.println(sol.lengthOfTheLongestSubString("a\nb\tc\rd")); // Expected: 4
    
        // 13. String with all possible ASCII characters
        StringBuilder allAscii = new StringBuilder();
        for (int i = 0; i < 128; i++) {
            allAscii.append((char)i);
        }
        System.out.println(sol.lengthOfTheLongestSubString(allAscii.toString())); // Expected: 128
    }
}

class Solution {
    int lengthOfTheLongestSubString(String source){
        List<Character> list = new ArrayList<>();
        int max = 0;
        for (int i = 0; i < source.length(); i++){
            while(list.contains(source.charAt(i))){
                list.remove(0);
            }
            list.add(source.charAt(i));
            max = Math.max(max, list.size());
        }
        return max;  // Missing return statement
    }
    int lengthOfTheLongestSubString(String s){
        Map<Character,Integer> dic = new HashMap<>();
        int i = -1 , res = 0 , len - s.length();
        for (int j = 0 ; j < len ; j++){
            if (dic.containsKey(s.charAt(j))){
                i = Math.max(i,dic.get(s.charAt(j)));
            }
            dis.put(s.charAt(j),j);
            res = Math.max(res,j-i);
        }
        return res;
    }
}
