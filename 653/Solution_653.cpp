class Solution {
public:
unordered_set<int> hash;
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        if(hash.count(k-root->val) > 0){
            return true;
        }
        hash.insert(root->val);
        return findTarget(root->left,k) || findTarget(root->right,k);
    }
};
