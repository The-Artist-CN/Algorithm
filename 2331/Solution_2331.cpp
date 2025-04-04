#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {};
    TreeNode(int val, TreeNode* left , TreeNode* right) : val(val) , left(left) , right(right) {};

}

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr) {
            return root->val;
        }
        if (root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        } else {
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
    }

    int evaluate(TreeNode* root){
        if (root->val == 0 || root->val == 1){
            return root->val;
        }

        int left_value = evaluate(root->left);
        int right_value = evaluate(root->right);

        if (root->val == 2){
            return left_value || right_value;
        } else {
            return left_value && right_value;
        }

        return -1;
    }
};

