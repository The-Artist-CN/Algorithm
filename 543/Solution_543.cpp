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

int main(){
    Solution sol;
    cls::ClsTreeNode* root = buildTree<cls::ClsTreeNode>({1, 2, 3, 4, 5, 6, 7});
        int expected = 4;
        int result = sol.diameterOfBT(root);
        std::cout << "Test Case - Balanced tree: "
             << (result == expected ? "PASSED" : "FAILED")
             << " (Expected: " << expected << ", Got: " << result << ")\n";
    return 0;
}
