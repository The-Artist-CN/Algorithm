/*
在 C++ 中，TreeNode* node 是一个指针，它本身是一个变量，存储了指向某个 TreeNode 对象的地址。如果你给它加上 &，即写成 TreeNode*& node，就变成了指针的引用。
是否可以加 &
是的，TreeNode* node 可以加 &，变成 TreeNode*& node。不过，是否需要加 & 取决于你想要实现的功能。

1. 普通指针 TreeNode* node
当函数参数是 TreeNode* node 时，函数接收的是指针的值（即地址的副本）。在函数内部，如果你修改了 node 的值（即让它指向另一个地址），这种修改只会作用于函数内部，对调用者的指针变量没有影响。
示例
void modify(TreeNode* node) {
    node = new TreeNode(42); // 修改的是 node 的副本
}

int main() {
    TreeNode* root = nullptr;
    modify(root); // 传入指针
    cout << (root == nullptr) << endl; // 输出 1，root 没有被修改
    return 0;
}

在这个例子中，modify 函数修改了 node，但它只是修改了 node 的副本，调用者的 root 仍然是 nullptr。

2. 指针的引用 TreeNode*& node
当函数参数是 TreeNode*& node 时，函数接收的是指针的引用。这样，函数内部对指针变量的修改会直接作用于调用者的指针变量。
示例
void modify(TreeNode*& node) {
    node = new TreeNode(42); // 修改的是调用者的指针
}

int main() {
    TreeNode* root = nullptr;
    modify(root); // 传入指针的引用
    cout << root->val << endl; // 输出 42，root 被修改了
    delete root;
    return 0;
}

在这个例子中，modify 函数修改了指针的引用，因此调用者的 root 被修改为指向一个新的 TreeNode。

总结

TreeNode* node：传递的是指针的值（地址的副本）。函数内部修改指针的值不会影响调用者的指针变量。
TreeNode*& node：传递的是指针的引用。函数内部修改指针的值会直接影响调用者的指针变量。


3. 什么时候需要加 &
是否需要加 & 取决于你的需求：


不需要修改指针本身：

如果函数只需要访问指针指向的内容，而不需要修改指针本身的值，就不需要加 &。
示例：遍历二叉树时，只需要访问节点的值。
void traverse(TreeNode* node) {
    if (!node) return;
    cout << node->val << endl;
    traverse(node->left);
    traverse(node->right);
}





需要修改指针本身：

如果函数需要修改指针本身的值（例如，让指针指向一个新的节点），就需要加 &。
示例：构造或修改树的结构。
void insert(TreeNode*& node, int val) {
    if (!node) {
        node = new TreeNode(val);
        return;
    }
    if (val < node->val) insert(node->left, val);
    else insert(node->right, val);
}






4. 使用场景对比
普通指针 TreeNode*
适合用在以下场景：

只需要读取指针指向的内容。
不需要修改指针本身。

指针的引用 TreeNode*&
适合用在以下场景：

需要修改指针本身，使其指向一个新的对象。
需要在递归或函数内部动态分配或重定向指针。


总结答案
TreeNode* node 可以加 &，变成 TreeNode*& node，这取决于是否需要修改指针本身的值。如果需要修改指针本身，使其指向新的地址，应该使用 TreeNode*&；否则，使用普通的 TreeNode* 即可。
如果还有疑问，请随时告诉我！😊
*/


#include <iostream>
#include <vector>
#include <climits> // 用于 INT_MAX
#include "TreeNode_CPP.h"
#include <algorithm>

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX; // 初始化最小差值为最大整数
        TreeNode* prev = nullptr; // 记录中序遍历的前一个节点

        // 中序遍历
        inorder(root, prev, minDiff);

        return minDiff;
    }

private:
    void inorder(TreeNode* node, TreeNode*& prev, int& minDiff) {
        if (!node) return;

        // 递归遍历左子树
        inorder(node->left, prev, minDiff);

        // 处理当前节点
        if (prev) {
            // 更新最小差值
            minDiff = std::min(minDiff, node->val - prev->val);
        }
        prev = node; // 更新前一个节点为当前节点

        // 递归遍历右子树
        inorder(node->right, prev, minDiff);
    }
};


int main() {
    // 构造二叉搜索树
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    std::cout << "Minimum difference: " << sol.getMinimumDifference(root) << std::endl;

    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

