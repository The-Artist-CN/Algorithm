#include <iostream>
#include "LOG_CPP.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

bool helper(TreeNode* root, int val);

bool isUnivalTree(TreeNode* root) {
    if (!root) return true; // 空树是单值二叉树
    int val = root->val; // 获取根节点的值
    return helper(root, val); // 调用辅助函数检查
}

bool helper(TreeNode* root, int val) {
    if (!root) return true; // 空节点不影响结果
    if (root->val != val) return false; // 如果节点值不等于根节点值，返回 false
    return helper(root->left, val) && helper(root->right, val); // 递归检查左右子树
}


class Solution {
public:
    bool isUniversal(TreeNode* root){
        if (!root) return true;
        if (root->left && root->val != root->left->val) return false;
        if (root->right && root->val != root->right->val) return false;

        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};

int main() {
    // 构建一个单值二叉树
    //     1
    //    / \
    //   1   1
    //  / \   \
    // 1   1   1
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);

    Solution sol;
    LOG_INFO("Apr 6 14:00PM : The second test result");
    cout << sol.isUniversal(root) << endl;

    // 构建一个非单值二叉树
    //     1
    //    / \
    //   1   2
    //  / \   \
    // 1   1   1
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(1);
    root2->right->right = new TreeNode(1);

    LOG_INFO("Apr 6 14:00PM : The second test result");
    cout << sol.isUniversal(root2) << endl;

    // 释放内存（简单示例中省略）
    return 0;
}
