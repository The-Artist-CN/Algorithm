#include <iostream>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// 提前声明 helper 函数
bool helper(TreeNode* root, int val);

// 判断是否是单值二叉树
bool isUnivalTree(TreeNode* root) {
    if (!root) return true; // 空树是单值二叉树
    int val = root->val; // 获取根节点的值
    return helper(root, val); // 调用辅助函数检查
}

// 辅助递归函数
bool helper(TreeNode* root, int val) {
    if (!root) return true; // 空节点不影响结果
    if (root->val != val) return false; // 如果节点值不等于根节点值，返回 false
    return helper(root->left, val) && helper(root->right, val); // 递归检查左右子树
}

// 测试代码
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

    cout << boolalpha << isUnivalTree(root) << endl; // 输出: true

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

    cout << boolalpha << isUnivalTree(root2) << endl; // 输出: false

    // 释放内存（简单示例中省略）
    return 0;
}
