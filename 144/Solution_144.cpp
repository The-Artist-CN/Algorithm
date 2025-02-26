#include <iostream>
#include <vector>

using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : value(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : value(x), left(left), right(right) {}
};

class Solution_144 {
public:
    // 后序遍历函数
    vector<int> post_order_traversal(TreeNode* root) {
        vector<int> target;
        post_order(root, target);
        return target;
    }

private:
    // 后序遍历递归实现
    void post_order(TreeNode* root, vector<int>& target) {
        if (root == nullptr) return;  // 如果节点为空，直接返回
        post_order(root->left, target);  // 递归访问左子树
        post_order(root->right, target); // 递归访问右子树
        target.push_back(root->value);   // 访问当前节点
    }
};

int main() {
    // 构建测试用例的二叉树
    // 二叉树结构：
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 创建 Solution 对象并调用后序遍历
    Solution_144 solution;
    vector<int> result = solution.post_order_traversal(root);

    // 输出结果
    cout << "Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

