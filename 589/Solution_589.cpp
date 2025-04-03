/*
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
*/

class First {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        helper(root,result);
        return result;
    }

    void helper(Node* root,vector<int>& res){
        if (root == nullptr){
            return ;
        }

        res.emplace_back(root->val);
        for (Node* p : root->children){
            helper(p,res);
        }
    }
};
