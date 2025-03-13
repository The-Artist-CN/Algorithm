#include <iostream>
#include <queue>
#include "TreeNode_CPP.h"
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 判断两个节点是否为堂兄弟节点
bool isCousins(TreeNode* root, int x, int y) {
    if (!root) return false;

    queue<pair<TreeNode*, TreeNode*>> q; // 存储 (当前节点, 父节点)
    q.push({root, nullptr});

    TreeNode* xParent = nullptr;
    TreeNode* yParent = nullptr;
    int xDepth = -1, yDepth = -1;
    int depth = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            auto [node, parent] = q.front();
            q.pop();

            // 记录 x 和 y 的父节点和深度
            if (node->val == x) {
                xParent = parent;
                xDepth = depth;
            }
            if (node->val == y) {
                yParent = parent;
                yDepth = depth;
            }

            // 将子节点加入队列
            if (node->left) q.push({node->left, node});
            if (node->right) q.push({node->right, node});
        }
        depth++;

        // 如果已经找到 x 和 y 的信息，提前退出
        if (xDepth != -1 && yDepth != -1) break;
    }

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
