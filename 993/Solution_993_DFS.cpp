#include <iostream>
#include "TreeNode_CPP.h"
using namespace std;


// DFS 辅助函数
void dfs(TreeNode* node, TreeNode* parent, int depth, int target, TreeNode*& targetParent, int& targetDepth) {
    if (!node) return;

    // 如果找到目标节点，记录其父节点和深度
    if (node->val == target) {
        targetParent = parent;
        targetDepth = depth;
        return;
    }

    // 递归遍历左子树和右子树
    dfs(node->left, node, depth + 1, target, targetParent, targetDepth);
    dfs(node->right, node, depth + 1, target, targetParent, targetDepth);
}

// 判断两个节点是否为堂兄弟节点
bool isCousins(TreeNode* root, int x, int y) {
    TreeNode* xParent = nullptr;
    TreeNode* yParent = nullptr;
    int xDepth = -1, yDepth = -1;

    // 查找 x 和 y 的父节点和深度
    dfs(root, nullptr, 0, x, xParent, xDepth);
    dfs(root, nullptr, 0, y, yParent, yDepth);

    // 判断是否为堂兄弟节点
    return xDepth == yDepth && xParent != yParent;
}

// 测试代码
int main() {
    // 构建二叉树
    //        1
    //       / \
    //      2   3
    //     /
    //    4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    // 测试用例
    cout << boolalpha; // 输出 bool 值为 true/false
    cout << "Are 4 and 3 cousins? " << isCousins(root, 4, 3) << endl; // false
    cout << "Are 2 and 3 cousins? " << isCousins(root, 2, 3) << endl; // false
    cout << "Are 4 and 5 cousins? " << isCousins(root, 4, 5) << endl; // false

    // 清理内存
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

