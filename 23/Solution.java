
public class Solution_23 {
    
    public ListNode mergeKLists(ListNode[] list){
        if (list == null || list.length == 0) return null;
        return mergeKLists(list,0,list.length);
    }

    private ListNode mergeKLists(ListNode[] list , int i , int j){
        int m = j - i;
        if (m == 0) return null;
        if (m == 1) return list[i];

        ListNode left = mergeKLists(list,i,i+m/2);
        ListNode right = mergeKLists(list,i+m/2,j);

        return mergeTwoLists(left,right);
    }

    private ListNode mergeTwoLists(ListNode left , ListNode right){
        ListNode dummy = new ListNode<>();
        ListNode cur = dummy;

        while (left != null && right != null){
            if (left.val <= right.val){
                cur.next = left;
                left = left.next;
            } else {
                cur.next = right;
                right = right.next;
            }
            cur = cur.next;
        }

        cur.next = left != null ? left : right ;
        return dummy.next
    }
}
