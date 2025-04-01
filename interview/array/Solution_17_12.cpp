#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {};
};

class Solution {

private:
    TreeNode* minNode;

public:
    TreeNode* convertBST(TreeNode* root){
        minNode = nullptr;
        reverseInorder(root);
        return minNode;
    }

private:
    void reverseInorder(TreeNode* root){
        if (root == nullptr){
            return ;
        }

        reverseInorder(root->right);

        root->right = minNode;
        minNode = root;

        reverseInorder(root->left);
        root->left = nullptr;
    }
};

TreeNode* buildTree(const vector<int>& nodes , int index){
    if (index >= nodes.size()) return nullptr;

    TreeNode* root = new TreeNode(nodes[index]);

    root->left =  buildTree(nodes,index * 2 + 1);
    root->right =  buildTree(nodes,index * 2 + 2);

    return root;

}


void printList(TreeNode* head) {
    cout << "[";
    while (head != nullptr) {
        cout << head->val;
        if (head->right != nullptr) {
            cout << ",null,";
        }
        head = head->right;
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    // 示例输入：[4,2,5,1,3,null,6,0]
    vector<int> nodes = {4, 2, 5, 1, 3, -1, 6, 0};
    TreeNode* root = buildTree(nodes, 0);
    TreeNode* head = solution.convertBST(root);
    printList(head);

    // 释放内存
    TreeNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->right;
        delete temp;
    }

    return 0;
}
