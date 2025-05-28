import java.util.*;

public class Solution_241 {
    public List<Integer> diffWaysToCompute(String expression) {
        List<Integer> res = new ArrayList<>();
        
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            
            if (c == '+' || c == '-' || c == '*') {
                String left = expression.substring(0, i);
                String right = expression.substring(i + 1);
                
                List<Integer> leftRes = diffWaysToCompute(left);
                List<Integer> rightRes = diffWaysToCompute(right);
                
                for (int l : leftRes) {
                    for (int r : rightRes) {
                        switch (c) {
                            case '+': res.add(l + r); break;
                            case '-': res.add(l - r); break;
                            case '*': res.add(l * r); break;
                        }
                    }
                }
            }
        }
        
        if (res.isEmpty()) {
            res.add(Integer.parseInt(expression));
        }
        
        return res;
    }
}
