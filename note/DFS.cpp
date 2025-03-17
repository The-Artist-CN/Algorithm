#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    std::vector<TreeNode*> children;
    TreeNode(int val) : val(val) , children({}) {};
};

void dfsRecursive(TreeNode* root){
    if(!root) return ;

    std::cout << root->val << " ";

    for (TreeNode* p : root->children){
        dfsRecursive(p);
    }
}


int main() {
    // 构建一个简单的树
    //       1
    //     / | \
    //    2  3  4
    //   / \
    //  5   6
    TreeNode* root = new TreeNode(1);
    root->children.push_back(new TreeNode(2));
    root->children.push_back(new TreeNode(3));
    root->children.push_back(new TreeNode(4));
    root->children[0]->children.push_back(new TreeNode(5));
    root->children[0]->children.push_back(new TreeNode(6));

    // 从根节点开始 DFS
    std::cout << "DFS Recursive: ";
    dfsRecursive(root);
    std::cout << std::endl;

    return 0;
}

