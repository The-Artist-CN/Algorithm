#include <iostream>
#include "TreeNode_CPP.h"
#include "LOG_CPP.h"

using namespace std;

//Apr 7 14:00PM
TreeNode* mergeTree(TreeNode* t1 , TreeNode* t2){
    if (!t1) return t2;
    if (!t2) return t1;
    t1->val += t2->val;
    t1->left = mergeTree(t1->left , t2->left);
    t1->right = mergeTree(t1->right, t2->right);
    return t1 ? t1 : t2;
}

int main(){

    vector<int> nums1 = {1, 3, 2, 5};
    vector<int> nums2 = {2, 1, 3, -1, 4, -1, 7};

    TreeNode* root1 = buildTree(nums1);
    TreeNode* root2 = buildTree(nums2);

    TreeNode* result = mergeTree(root1,root2);

    LOG_INFO("Apr 7 15:00PM Test passed ");
    printTree(result);

    return 0;
}
