#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // for std::max
#include "TreeNode_CPP.h"
#include <climits>


class Solution {
private:
    void countFrequencies(TreeNode* root, std::unordered_map<int, int>& m) {
        if (!root) return;

        countFrequencies(root->left, m);
        m[root->val]++;
        countFrequencies(root->right, m);
    }

public:
    std::vector<int> findMode(TreeNode* root) {
        if (!root) return {};

        std::unordered_map<int, int> m;
        countFrequencies(root, m);

        int maxc = INT_MIN;
        for (const auto& entry : m) {
            maxc = std::max(maxc, entry.second);
        }

        std::vector<int> v;
        for (const auto& entry : m) {
            if (entry.second == maxc) {
                v.push_back(entry.first);
            }
        }

        return v;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(2);

    Solution s;
    std::vector<int> v = s.findMode(root);

    std::cout << "众数：";
    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Clean up memory
    delete root->left->right;
    delete root->left;
    delete root;

    return 0;
}
