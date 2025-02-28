#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {};
};

int countNodes(TreeNode* root ){
    if ( !root ) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


int main() {
    // 构建完全二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "节点总数: " << countNodes(root) << endl; // 输出 6

    return 0;
}
