import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution_394 {

    public List<Integer> intersection(int[] num1, int[] num2) {
        List<Integer> result = new ArrayList<>();
        Map<Integer, Integer> frequencyMap = new HashMap<>();

        for (int num : num1) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        for (int num : num2) {
            if (frequencyMap.containsKey(num)) {
                int count = frequencyMap.get(num);
                if (count > 0) {
                    result.add(num);
                    frequencyMap.put(num, count - 1);
                }
            }
        }

        return result;
    }

}