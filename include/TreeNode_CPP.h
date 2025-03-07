#ifndef TREENODE_CPP_H
#define TREENODE_CPP_H

#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {};

    ~TreeNode() { delete left ; delete right; };

};

TreeNode* createTreeNode(int val){
    return new TreeNode(val);
}


#endif
