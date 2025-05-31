public class Solution_95 {

    public List<TreeNode> generateTrees(int n) {
        if (n == 0) {
            return new ArrayList<TreeNode>();
        }
        return generateTrees(1, n);
    }

    private List<TreeNode> generateTrees(int start, int end) {
        List<TreeNode> allTrees = new ArrayList<>();

        // 递归终止条件：start > end时，表示没有数字可以构成子树，返回null
        if (start > end) {
            allTrees.add(null);
            return allTrees;
        }

        // 枚举所有可能的根节点
        for (int i = start; i <= end; i++) {
            // 递归生成所有可能的左子树
            List<TreeNode> leftTrees = generateTrees(start, i - 1);
            // 递归生成所有可能的右子树
            List<TreeNode> rightTrees = generateTrees(i + 1, end);

            // 将左右子树组合到根节点上
            for (TreeNode left : leftTrees) {
                for (TreeNode right : rightTrees) {
                    TreeNode root = new TreeNode(i);
                    root.left = left;
                    root.right = right;
                    allTrees.add(root);
                }
            }
        }
        return allTrees;
    }
}
