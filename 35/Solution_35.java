import java.util.Scanner;




public class Solution_35 {
    
    public static int binarySearch(int[] nums , int numsize , int target){
        int left = 0 , right = numsize - 1;
        while (left <= right ){
            int mid = (left+right)/2;
            if (nums[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    public static void main(String[] args){
        int[] array = {1,3,5,6,7,8,9};
        int arraysize = array.length;
        int target;

        Scanner scan = new Scanner(System.in);
        
        System.out.print("请输入你的目标值:");
        target = scan.nextInt();

        int result = binarySearch(array,arraysize,target);

        System.out.println("目标值应插入的位置索引为: " + result);

        scan.close();
    }
}

