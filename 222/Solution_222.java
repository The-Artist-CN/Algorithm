public class Solution_222 {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
        System.out.println("Basic count: " + countNode(root));
        System.out.println("Advanced count: " + advanced_countNode(root));
    }

    // Basic recursive node count (O(n) time)
    public static int countNode(TreeNode root) {
        if (root == null) return 0;
        int left = countNode(root.left);
        int right = countNode(root.right);
        return left + right + 1;
    }

    // Advanced count using tree height (O(log n)^2 time)
    public static int advanced_countNode(TreeNode root) {
        if (root == null) return 0;
        int left_height = getHeight(root.left);
        int right_height = getHeight(root.right);

        if (left_height == right_height) {
            return (1 << left_height) + advanced_countNode(root.right);
        } else {
            return (1 << right_height) + advanced_countNode(root.left);
        }
    }

    // Helper method to get height by following left subtree
    public static int getHeight(TreeNode head) {
        int h = 0;
        while (head != null) {
            h++;
            head = head.left;
        }
        return h;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    public TreeNode() {}
    public TreeNode(int val) {
        this.val = val;
    }
    public TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
