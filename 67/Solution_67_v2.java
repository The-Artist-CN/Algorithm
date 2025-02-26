

public class Solution_67_v2 {
    public static void main(String[] args){
        String a = "1010";
        String b = "1101";
        String sum = addBinary(a, b);
        System.out.println("二进制和: " + sum); 
    }

    public static String addBinary(String a , String b){
        StringBuilder result = new StringBuilder();
        int a_len = a.length();
        int b_len = b.length();
        int carry = 0;

        for (int i = 0 ; i < Math.max(a_len , b_len); i++){
            int digitA = (i < a_len) ? a.charAt(a_len - 1 - i) - '0' : 0;
            int digitB = (i < b_len) ? b.charAt(b_len - 1 - i) - '0' : 0;

            int sum = digitA + digitB + carry;
            result.append(sum % 2);
            carry = sum / 2;
        }

        if (carry > 0){result.append(carry);};

        return result.reverse().toString();
    }
}
