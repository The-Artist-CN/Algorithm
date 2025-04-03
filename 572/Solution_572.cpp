#include <iostream>
#include "TreeNode_CPP.h"

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

bool isSubtree(TreeNode* host , TreeNode* sub){
    if (!host || !sub) return false;
    if (isSame(host,sub)) return true;
    return isSubtree(host->left,sub) || isSubtree(host->right,sub);
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

    // 检查是否为子树
    if (isSubtree(root, subRoot)) {
        cout << "subRoot 是 root 的子树" << endl;
    } else {
        cout << "subRoot 不是 root 的子树" << endl;
    }

    // 清理内存（这里可以加释放内存代码）
    return 0;
}
