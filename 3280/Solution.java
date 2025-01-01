public class Solution {

  private String binary(int x){
    StringBuilder s = new StringBuilder();
        for (; x != 0; x >>= 1) {
            s.append(x & 1);
        }
        return s.reverse().toString();

  }

  public String convertDateToBinary(String date) {
        int year = Integer.parseInt(date.substring(0, 4));
        int month = Integer.parseInt(date.substring(5, 7));
        int day = Integer.parseInt(date.substring(8, 10));
        return binary(year) + "-" + binary(month) + "-" + binary(day);
    }


  public static void main(Strings[] args){
    Date today = new Date();
    System.out.println(convertDateToBinary(today));
  }
}
