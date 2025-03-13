#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {};
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root){
        return dfs(root,0);
    }
private:
    int dfs(TreeNode* node , int currentSum){
        if (!node) return 0;

        currentSum = (currentSum << 1) | node->val;

        if (!node->left && !node->right) return currentSum;

        return dfs(node->left,currentSum) + dfs(node->right,currentSum);
    }
};

int main() {
    // 构建示例二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(0);

    Solution solution;
    int result = solution.sumRootToLeaf(root);
    std::cout << "Result: " << result << std::endl; // 输出应为 15

    // 释放内存（可选，实际开发中建议使用智能指针）
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
