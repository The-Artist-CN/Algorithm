
public class Solution_110 {
    public static void main(String[] args) {
        // 示例测试代码
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        Solution solution = new Solution();
        System.out.println(solution.isBalanced(root)); // 输出：true
    }
}

class Solution {
    // 判断是否是平衡二叉树
    public boolean isBalanced(TreeNode root) {
        return checkHeight(root) != -1;
    }

    // 辅助函数：检查树的高度，同时判断是否平衡
    private int checkHeight(TreeNode root) {
        if (root == null) {
            return 0; // 空树高度为 0
        }

        // 递归计算左子树的高度
        int leftHeight = checkHeight(root.left);
        if (leftHeight == -1) {
            return -1; // 如果左子树不平衡，直接返回 -1
        }

        // 递归计算右子树的高度
        int rightHeight = checkHeight(root.right);
        if (rightHeight == -1) {
            return -1; // 如果右子树不平衡，直接返回 -1
        }

        // 检查当前节点的左右子树高度差是否超过 1
        if (Math.abs(leftHeight - rightHeight) > 1) {
            return -1; // 如果不平衡，返回 -1
        }

        // 返回当前子树的高度
        return Math.max(leftHeight, rightHeight) + 1;
    }
}

/*
class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

*/
