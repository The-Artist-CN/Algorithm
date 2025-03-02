#include <iostream>
#include <vector>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};


void collectLeafValue( TreeNode* root , vector<int>& leafs ){
    if ( !root ) return ;
    if ( !root->left && !root->right ){
        leafs.push_back(root->val);
    }

    collectLeafValue( root->left , leafs);
    collectLeafValue( root->right , leafs);
}

vector<int> getLeafs( TreeNode* root){
    vector<int> result;
    collectLeafValue( root , result );
    return result;
}


int main() {
    // 构建一棵二叉树
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    //       / \
    //      7   8
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);

    // 获取叶值序列
    vector<int> leafSequence = getLeafs(root);

    // 输出叶值序列
    cout << "叶值序列: ";
    for (int val : leafSequence) {
        cout << val << " ";
    }
    cout << endl;

    // 释放内存（简单示例中省略）
    return 0;
}
