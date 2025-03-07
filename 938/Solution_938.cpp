#include "TreeNode_CPP.h"


class Solution {
public:
    int rangeSumBST(TreeNode* root , int low , int high){
        if (root == nullptr) return 0;

        if (root->val < low){
            return rangeSumBST(root->right , low , high);
        }

        if (root->val > high){
            return rangeSumBST(root->left , low , high);
        }

        return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
    }
};

int main() {
    // 示例：构建一个二叉搜索树
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    Solution solution;
    int low = 7, high = 15;
    int result = solution.rangeSumBST(root, low, high);

    std::cout << "范围 [" << low << ", " << high << "] 之间的节点值的和: " << result << std::endl; // 输出结果
    return 0;
}
