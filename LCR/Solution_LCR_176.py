class TreeNode :
    def __init__(self,val = 0 , left = None , right = None):
        self.val = val;
        self.left = left;
        self.right = right;

class Solution :
    def isBalanced(self,root:TreeNode) -> bool :
        def check(node):
            if not node:
                return 0;
            L = check(node.left);
            if L == -1 :
                return -1;
            R = check(node.right);
            if R == -1 :
                return -1;

            if abs(L - R) > 1 :
                return -1;

            return max(L,R) + 1;
        return check(root) != -1;


def main() :
    s = Solution();
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)
    root.left.left.left = TreeNode(8)
    root.left.left.right = TreeNode(9)
    print(s.isBalanced(root));


if __name__ == "__main__" :
    main()
