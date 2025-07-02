#include <iostream>
#include <vector>
using namespace std;

/*  定义 struct TreeNode

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0) , left(nullptr) , right(nullptr) {};
        TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {};
        TreeNode(int val , TreeNode *left , TreeNode *right) : val(val) , left(nullptr) , right(nullptr) {};

    }

*/
// 递归函数，将升序数组转换为平衡二叉搜索树
TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
    // 递归终止条件
    if (left > right) {
        return nullptr;
    }
    
    // 找到中间位置
    int mid = left + (right - left) / 2;
    
    // 创建当前节点
    TreeNode* root = new TreeNode(nums[mid]);
    
    // 构造左子树
    root->left = sortedArrayToBST(nums, left, mid - 1);
    
    // 构造右子树
    root->right = sortedArrayToBST(nums, mid + 1, right);
    
    return root;
}

// 主函数，封装调用
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

// 辅助函数：打印二叉树（中序遍历）
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // 输入一个升序数组
    vector<int> nums = {-10, -3, 0, 5, 9};
    
    // 转换为平衡二叉搜索树
    TreeNode* root = sortedArrayToBST(nums);
    
    // 打印中序遍历结果
    cout << "中序遍历结果: ";
    inorderTraversal(root);
    cout << endl;
    
    return 0;
}

