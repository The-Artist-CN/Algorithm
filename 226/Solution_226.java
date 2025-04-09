public class Solution_226 {
    public static void main(String[] args) {
        Solution_226 s = new Solution_226();
        TreeNode root = new TreeNode(1,
                new TreeNode(2,
                        new TreeNode(4, null, null),
                        new TreeNode(5, null, null)),
                new TreeNode(3,
                        new TreeNode(6, null, null),
                        new TreeNode(7, null, null)));
        
        System.out.println("Original tree (in-order):");
        s.inOrderTraversal(root);
        System.out.println();
        
        s.swapTree(root);
        
        System.out.println("Swapped tree (in-order):");
        s.inOrderTraversal(root);
        System.out.println();
    }

    public TreeNode swapTree(TreeNode root) {
        if (root == null) return null;
        
        TreeNode leftTree = swapTree(root.left);
        TreeNode rightTree = swapTree(root.right);
        
        root.left = rightTree;
        root.right = leftTree;
        
        return root;
    }

    public void inOrderTraversal(TreeNode root) {
        if (root == null) {
            System.out.print("null ");
            return;
        }
        
        inOrderTraversal(root.left);
        System.out.print(root.val + " ");
        inOrderTraversal(root.right);
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
