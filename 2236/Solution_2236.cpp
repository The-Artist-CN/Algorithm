class Solution {
public:
    bool checkTree(TreeNode* root) {
        // Base case: If the node is null, return true
        if (root == nullptr) {
            return true;
        }
        
        // Check if the node has both left and right children
        if (root->left != nullptr && root->right != nullptr) {
            // Check if the current node's value equals the sum of its left and right child values
            if (root->val != root->left->val + root->right->val) {
                return false;
            }
        }
        
        // Recursively check the left and right subtrees
        return checkTree(root->left) && checkTree(root->right);
    }
};

