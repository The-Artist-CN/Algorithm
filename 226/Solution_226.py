class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        
        leftTree = self.invertTree(root.left)
        rightTree = self.invertTree(root.right)
        
        root.left = rightTree
        root.right = leftTree
        
        return root
    
    def printTreeInOrder(self, root: TreeNode):
        if not root:
            print("null", end=" ")
            return
        
        self.printTreeInOrder(root.left)
        print(root.val, end=" ")
        self.printTreeInOrder(root.right)

if __name__ == "__main__":
    s = Solution()
    
    # Test Case 1: Normal binary tree
    root1 = TreeNode(4,
                   TreeNode(2,
                          TreeNode(1),
                          TreeNode(3)),
                   TreeNode(7,
                          TreeNode(6),
                          TreeNode(9)))
    
    print("Original tree (in-order):")
    s.printTreeInOrder(root1)
    print("\nInverted tree (in-order):")
    inverted1 = s.invertTree(root1)
    s.printTreeInOrder(inverted1)
    print("\n")
    
    # Test Case 2: Empty tree
    root2 = None
    print("Original empty tree:")
    s.printTreeInOrder(root2)
    print("\nInverted empty tree:")
    inverted2 = s.invertTree(root2)
    s.printTreeInOrder(inverted2)
    print("\n")
    
    # Test Case 3: Single node tree
    root3 = TreeNode(1)
    print("Original single node tree:")
    s.printTreeInOrder(root3)
    print("\nInverted single node tree:")
    inverted3 = s.invertTree(root3)
    s.printTreeInOrder(inverted3)
