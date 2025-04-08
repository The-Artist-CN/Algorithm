#include <vector>
#include <algorithm>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
//Apr 8 9:30PM
class Solution {
public:
    int maxDepth(Node* root) {
        // 如果节点为空，深度为0
        if (!root) return 0;
        
        int depth = 0;
        // 遍历所有子节点
        for (Node* child : root->children) {
            // 递归计算每个子节点的深度，并保持最大值
            depth = max(depth, maxDepth(child));
        }
        
        // 当前节点的深度是子节点最大深度+1
        return depth + 1;
    }
};
