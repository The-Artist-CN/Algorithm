#include <iostream>
#include <vector>
#include "TreeNode_CPP.h"

void inorderTraversal(TreeNode* root, std::vector<int>& vec) {
    if (!root) return;
    inorderTraversal(root->left, vec);
    vec.push_back(root->val);
    inorderTraversal(root->right, vec);
}

TreeNode* increasingBST(TreeNode* root) {
    std::vector<int> vec;
    inorderTraversal(root, vec);
    TreeNode dummy(0); // 虚拟节点
    TreeNode* current = &dummy;

    for (int val : vec) {
        current->right = new TreeNode(val); // 创建新节点
        current = current->right; // 移动到新节点
    }

    return dummy.right; // 返回新树的根节点
}

void printTree(TreeNode* root) {
    while (root) {
        std::cout << root->val << " ";
        root = root->right; // 只遍历右子树
    }
    std::cout << std::endl;
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root; // 释放当前节点
}

int main() {
    // 示例：构建一棵二叉搜索树
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(9);

    TreeNode* newRoot = increasingBST(root); // 重新排列树
    printTree(newRoot); // 输出: 2 3 4 5 8 9

    // 释放内存
    deleteTree(newRoot); // 释放新树的内存

    return 0;
}

