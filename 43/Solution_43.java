public class Solution_43 {
    

    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) return "0";
        
        int n1 = num1.length(), n2 = num2.length();
        int[] result = new int[n1 + n2];
        
        // Multiply each digit and sum at the appropriate position
        for (int i = n1 - 1; i >= 0; i--) {
            int digit1 = num1.charAt(i) - '0';
            for (int j = n2 - 1; j >= 0; j--) {
                int digit2 = num2.charAt(j) - '0';
                int product = digit1 * digit2;
                int sum = result[i + j + 1] + product;
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        // Remove leading zeros
        int start = 0;
        while (start < result.length && result[start] == 0) {
            start++;
        }
        
        // Build the result string
        StringBuilder sb = new StringBuilder();
        for (int i = start; i < result.length; i++) {
            sb.append(result[i]);
        }
        
        return sb.toString();
    }
}