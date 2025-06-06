#include <iostream>
using namespace std;

// 定义二叉树节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true; // 空树是对称的
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* ltree, TreeNode* rtree) {
        if (!ltree && !rtree) return true;  // 两棵子树都为空，对称
        if (!ltree || !rtree) return false; // 只有一棵子树为空，不对称

        // 判断当前节点值是否相等，并递归检查左右子树是否镜像对称
        return (ltree->val == rtree->val) &&
               isMirror(ltree->left, rtree->right) &&
               isMirror(ltree->right, rtree->left);
    }
};

int main() {
    // 构造一个对称二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // 创建 Solution 实例并检查是否对称
    Solution solution;
    if (solution.isSymmetric(root)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}

