import java.util.HashMap;
import java.util.Map;

public class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] strs = str.split(" ");
        if (pattern.length() != str.length()) return false;
        Map<Object,Integer> map = new HashMap<>();
        for (Integer i = 0 ; i < pattern.length() ; i++){
            if (map.put(pattern.charAt(i),i) != map.put(strs[i],i)){
                return false;
            }
        }
        return true;
    }
}