#include "Advanced_TreeNode_CPP.h"
#include <algorithm>

class Solution {
    int ans = 0;  // Now tracks maximum number of edges (diameter)

    int depth(cls::ClsTreeNode* root) {
        if (!root) return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        ans = std::max(ans, L + R);  // Count edges, not nodes
        return std::max(L, R) + 1;
    }

public:
    int diameterOfBT(cls::ClsTreeNode* root) {
        depth(root);
        return ans;
    }
};


// Mar 3 15:00PM
class Solution {
    int ans = 1;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans - 1;
    }
private:
    int depth(TreeNode* node){
        if (node == nullptr){
            return 0;
        }
        int left = depth(node->left);
        int right = depth(node->right);
        ans = max(ans,left+right+1);
        return max(left,right) + 1;
    }
};
