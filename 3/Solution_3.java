import java.util.ArrayList;
import java.util.List;

public class Solution_3 {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.isEmpty()) {
            return 0;
        }

        Map<Character, Integer> map = new HashMap<>();
        int left = 0;
        int max = 0;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s.charAt(right);

            // 如果当前字符已经存在，并且其索引 >= left，则更新 left
            if (map.containsKey(currentChar) && map.get(currentChar) >= left) {
                left = map.get(currentChar) + 1; // 直接跳到重复字符的下一个位置
            }

            map.put(currentChar, right); // 更新字符的最新位置
            max = Math.max(max, right - left + 1);
        }

        return max;
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
