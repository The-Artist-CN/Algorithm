#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : value(x) , left(nullptr) , right(nullptr) {};
};

bool hasPathSum( TreeNode* root , int target){
    if ( !root ) return false;

    if ( !root->left && !root->right){
        return root->value = target;
    }

    return hasPathSum( root->left,target - root->value) || hasPathSum( root->right , target - root->value );
}


// 测试代码
int main() {
    // 构建一个二叉树
    //       5
    //      / \
    //     4   8
    //    /   / \
    //   11  13  4
    //  /  \      \
    // 7    2      1
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    // 检查是否存在路径和为 22 的路径
    if (hasPathSum(root, 22)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    // 释放内存（简单示例中省略）
    return 0;
}
