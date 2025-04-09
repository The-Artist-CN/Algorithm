#ifndef ADVANCED_TREE_NODE_H
#define ADVANCED_TREE_NODE_H

#include <iostream>
#include <vector>
#include <queue>
#include <type_traits>

namespace cls {
    class ClsTreeNode {
    public:
        int val;
        ClsTreeNode* left;
        ClsTreeNode* right;

        ClsTreeNode() : val(0), left(nullptr), right(nullptr) {}
        ClsTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        ClsTreeNode(int x, ClsTreeNode* left, ClsTreeNode* right) : val(x), left(left), right(right) {}
    };
}

namespace str {
    struct StrTreeNode {
        int value;
        StrTreeNode* left;
        StrTreeNode* right;

        StrTreeNode() : value(0), left(nullptr), right(nullptr) {}
        StrTreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
        StrTreeNode(int val, StrTreeNode* left, StrTreeNode* right) : value(val), left(left), right(right) {}
    };
}

template <typename TreeNodeType>
TreeNodeType* createNode(int val) {
    return new TreeNodeType(val);
}

template <typename TreeNodeType>
TreeNodeType* buildTree(const std::vector<int>& nums) {
    if (nums.empty() || nums[0] == -1) return nullptr;
    TreeNodeType* root = new TreeNodeType(nums[0]);
    std::queue<TreeNodeType*> q;
    q.push(root);
    int index = 1;
    while (!q.empty() && index < nums.size()) {
        TreeNodeType* cur = q.front();
        q.pop();
        if (index < nums.size() && nums[index] != -1) {
            cur->left = new TreeNodeType(nums[index]);
            q.push(cur->left);
        }
        index++;
        if (index < nums.size() && nums[index] != -1) {
            cur->right = new TreeNodeType(nums[index]);
            q.push(cur->right);
        }
        index++;
    }
    return root;
}

template <typename TreeNodeType>
void printTree(TreeNodeType* root) {
    if (!root) {
        std::cout << "[]" << std::endl;
        return;
    }

    std::queue<TreeNodeType*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNodeType* current = q.front();
        q.pop();
        if (current) {
            if constexpr (std::is_same<TreeNodeType, cls::ClsTreeNode>::value) {
                std::cout << current->val << " ";
            } else if constexpr (std::is_same<TreeNodeType, str::StrTreeNode>::value) {
                std::cout << current->value << " ";
            }
            q.push(current->left);
            q.push(current->right);
        } else {
            std::cout << "null ";
        }
    }

    std::cout << std::endl;
}

template <typename TreeNodeType>
void deleteTree(TreeNodeType* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

#endif

