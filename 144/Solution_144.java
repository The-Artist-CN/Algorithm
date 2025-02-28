

public class Solution_144 {
    public static void main(String[] args){
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        // 调用先序遍历方法
        preorderTraversal(root);
    }

    public static void preorderTraversal( TreeNode root ){
        if ( root == null ) return ;
        System.out.println( root.val );
        preorderTraversal(root.left);
        preorderTraversal(root.right);
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode( int val ){ this.val = val; };
};
