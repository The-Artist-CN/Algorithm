class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;

        while (!stk.empty() || root ){
            while (root != nullptr){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            result.push_back(root->val);
            stk.pop();
            root = root->right;
        }
        return result;
    }
};
