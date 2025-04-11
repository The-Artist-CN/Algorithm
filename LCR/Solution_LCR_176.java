
class Solution_LCR_176 {
    public static void main(String[] args) {
        Solution_LCR_176 solution = new Solution_LCR_176();

        // Test case 1: Balanced tree
        TreeNode root1 = new TreeNode(1,
                            new TreeNode(2,
                                new TreeNode(4),
                                new TreeNode(5)),
                            new TreeNode(3));
        System.out.println(solution.isBalanced(root1)); // Should print true

        // Test case 2: Unbalanced tree
        TreeNode root2 = new TreeNode(1,
                            new TreeNode(2,
                                new TreeNode(4,
                                    new TreeNode(6),
                                    null),
                                new TreeNode(5)),
                            new TreeNode(3));
        System.out.println(solution.isBalanced(root2)); // Should print false
    }

    public boolean isBalanced(TreeNode root) {
        return check(root) != -1;
    }

    private int check(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int L = check(root.left);
        if (L == -1) return -1;

        int R = check(root.right);
        if (R == -1) return -1;

        if (Math.abs(L - R) > 1) return -1;

        return Math.max(L, R) + 1;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}
    TreeNode(int val) {
        this.val = val;
    }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
