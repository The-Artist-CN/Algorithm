class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}


public class Solution_138 {
    public Node copyRandomList(Node head) {
        if (head == null) return null;

        Map<Node,Node> map = new HashMap<Node,Node>();

        Node cur = head;

        while (cur != null){
            map.put(cur,new Node(cur.val));
            cur = cur.next;
        }

        cur = head;

        while (cur != null){
            Node nn = map.get(cur);
            nn.next = map.get(cur.next);
            nn.next = map.get(cur.random);
            cur = cur.next;
        }

        return map.get(head);
    }
}
