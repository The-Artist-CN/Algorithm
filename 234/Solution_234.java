import java.util.Stack;

class ListNode {
    
    int val;

    ListNode next;

    ListNode(int val){this.val = val;};
}

public class Solution_234 {

    public static boolean isPalindrome(ListNode head){
        
        if (head == null || head.next == null){
            return true;
        }

        Stack<Integer> stack = new Stack<>();
        
        ListNode current = head;

        while ( current != null){
            stack.push(current.val);
            current = current.next;
        }

        current = head;


        while(current != null){
           
           int value = current.val;
           if (value != stack.pop()){
              return false;
           }

          current = current.next;
        }
       return true;

    }

   public static void main(String[] args){
      ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(2);
        head.next.next.next = new ListNode(1); 

        System.out.println(isPalindrome(head));
   }
}
