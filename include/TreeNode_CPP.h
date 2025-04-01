#ifndef TREENODE_CPP_H
#define TREENODE_CPP_H

#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

    TreeNode* createTreeNode(int val){
        return new TreeNode(val);
    }

};



#endif
