#include <iostream>
#include "TreeNode_CPP.h"
#include "LOG_CPP.h"

using namespace std;

bool isSame(TreeNode* t1 , TreeNode* t2){
    if (!t1 && !t2){
        return true;
    }

    if (!t1 || !t2){
        return false;
    }

    if (t1->val != t2->val){
        return false;
    }

    return isSame(t1->left,t2->left) && isSame(t1->right,t2->right);

}

bool isSub(TreeNode* host , TreeNode* sub){
    if (!host || !sub) return false;
    if (isSame(host,sub)) return true;
    return isSub(host->left,sub) || isSub(host->right,sub);
}

//Apr 7 13:00PM

bool isSameTree(TreeNode* t1 , TreeNode* t2){
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    if (t1->val != t2->val) return false;
    return isSameTree(t1->left , t2->left) || isSameTree(t1->right,t2->right);
}

bool isSubTree(TreeNode* host , TreeNode* sub){
    if (!host || !sub) return false;
    if (isSameTree(host,sub)) return true;
    return isSubTree(host->left,sub) || isSubTree(host->right,sub);
}


// 测试代码
int main() {
    // 构建示例二叉树
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    if (isSubTree(root, subRoot)) {
        LOG_INFO("subRoot 是 root 的子树");
    } else {
        LOG_INFO("subRoot 不是 root 的子树");
    }

    // 清理内存（这里可以加释放内存代码）
    return 0;
}
