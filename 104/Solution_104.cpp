class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max = INT_MIN;
        max = indepth(root);
        return max;
    }

private:
    int indepth(TreeNode* root){
        if (!root) return 0 ;
        int left = indepth(root->left);
        int right = indepth(root->right);
        return max(left,right) + 1;

    }
};
