#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义树的节点结构
struct TreeNode {
    int value; // 节点的值
    vector<TreeNode*> children; // 存储子节点的指针

    // 构造函数
    TreeNode(int val) : value(val) {}
};

// BFS 遍历树
void BFS(TreeNode* root) {
    if (!root) return; // 如果树为空，直接返回

    // 创建一个队列用于 BFS
    queue<TreeNode*> q;
    q.push(root); // 将根节点加入队列

    while (!q.empty()) {
        TreeNode* current = q.front(); // 取出队列中的第一个节点
        q.pop();
        cout << current->value << " "; // 输出当前节点的值

        // 将当前节点的所有子节点加入队列
        for (TreeNode* child : current->children) {
            q.push(child);
        }
    }
}

int main() {
    // 创建一棵树
    TreeNode* root = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);

    // 构建树结构
    root->children.push_back(node2);
    root->children.push_back(node3);
    node2->children.push_back(node4);
    node2->children.push_back(node5);
    node3->children.push_back(node6);

    // 从根节点开始 BFS 遍历
    cout << "BFS traversal of the tree: ";
    BFS(root);

    // 释放内存（避免内存泄漏）
    delete root;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;

    return 0;
}
