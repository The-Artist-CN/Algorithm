
public class Solution {

    public void flatten(TreeNode root) {
        TreeNode cur = root;
        while (cur != null) {
            if (cur.left != null) {
                TreeNode right = cur.right;
                TreeNode left = cur.left;
                TreeNode next = left;
                while (next.right != null) {
                    next = next.right;
                }
                next.right = right;
                cur.left = null;
                cur.right = left;
            }
            cur = cur.right;
        }
    }
}