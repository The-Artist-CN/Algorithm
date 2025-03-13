#include <iostream>
#include <climits>
#include "TreeNode_CPP.h"
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> findMode(TreeNode* root){
        vector<int> result;
        int prev = INT_MIN, maxCount = 0 , currentCount = 0;
        traverse(root,prev,maxCount,currentCount,result);
        return result;
    }
private:
    void traverse(TreeNode* node , int& prev,int& maxCount , int& currentCount , vector<int>& result){

        if(!node) return ;

        traverse(node->left,prev,maxCount,currentCount,result);

        if(node->val == prev){
            currentCount++;
        } else {
            currentCount = 1;
        }

        if (currentCount > maxCount){
            maxCount = currentCount;
            result.clear();
            result.push_back(node->val);
        } else if( currentCount == maxCount ) {
            result.push_back(node->val);
        }

        prev = node->val;
        
        traverse(node->right,prev,maxCount,currentCount,result);
        
    }
};


int main() {
    // 构建示例二叉树
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->left = new TreeNode(3);

    Solution solution;
    vector<int> result = solution.findMode(root);

    cout << "Modes: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // 释放内存（可选，实际开发中建议使用智能指针）
    delete root->right->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
