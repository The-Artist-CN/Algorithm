class ListNode {
    int val;
    ListNode next;

    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class Solution_21 {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        // 创建一个哑节点，用于简化操作
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;

        // 遍历两个链表，比较每个节点的值
        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                current.next = list1;
                list1 = list1.next; // 移动 list1 指针
            } else {
                current.next = list2;
                list2 = list2.next; // 移动 list2 指针
            }
            current = current.next; // 移动 current 指针
        }

        // 处理剩余的节点
        if (list1 != null) {
            current.next = list1;
        } else {
            current.next = list2;
        }

        // 返回合并后的链表头
        return dummy.next;
    }

    public void Test_01() {
        // 创建测试用例
        ListNode list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
        ListNode list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

        // 调用方法进行合并
        ListNode mergedList = mergeTwoLists(list1, list2);

        // 输出结果
        printList(mergedList); // 期望输出: 1 -> 1 -> 2 -> 3 -> 4 -> 4
    }

    // 辅助方法：打印链表
    private void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val);
            if (head.next != null) {
                System.out.print(" -> ");
            }
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Solution_21 solution = new Solution_21();
        solution.Test_01(); // 执行测试方法
    }
}

