#ifndef TREENODE_CPP_H
#define TREENODE_CPP_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

    static TreeNode* createTreeNode(int val){
        return new TreeNode(val);
    }

};

TreeNode* createNode(int val) {
    return new TreeNode(val);
}

TreeNode* buildTree(const vector<int>& nums) {
    if (nums.empty() || nums[0] == -1) return nullptr; // 空树或无效输入
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nums.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (nums[i] != -1) {
            node->left = new TreeNode(nums[i]);
            q.push(node->left);
        }
        i++;
        if (i < nums.size() && nums[i] != -1) {
            node->right = new TreeNode(nums[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

void printTree(TreeNode* root){
    if (!root){
        cout << "[]" << endl;
        return ;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        if (current){
            cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        } else {
            cout << "null "; 
        }
    }

    cout << endl;
    
}


#endif
