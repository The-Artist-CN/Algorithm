import java.util.HashMap;
import java.util.Map;

public class Solution_290 {
    public boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");
        if (words.length != pattern.length()) {
            return false;
        }

        Map<Object, Integer> map = new HashMap<>();

        for (Integer i = 0; i < words.length; i++) {  // Use Integer to handle null
            char c = pattern.charAt(i);
            String word = words[i];

            // Check if the pattern character and word have the same mapping
            if (map.put(c, i) != map.put(word, i)) {
                return false;
            }
        }

        return true;
    }
}