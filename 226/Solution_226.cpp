#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode( int val ) : val(val) , left(nullptr) , right(nullptr) {};
};

void preorderTraversal( TreeNode* root ){
    if ( !root ) return ;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

TreeNode* invertTree( TreeNode* root ){
    if ( !root ) return nullptr;

    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);

    root->left = right;
    root->right = left;

    return root;
}

int main() {
    // 创建二叉树
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // 输出翻转前的树结构
    cout << "翻转前的树：";
    preorderTraversal(root);
    cout << endl;

    // 翻转二叉树
    root = invertTree(root);

    // 输出翻转后的树结构
    cout << "翻转后的树：";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
