//给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。
//
//
//
// 示例 1：
//
//
//输入：nums = [-10,-3,0,5,9]
//输出：[0,-3,9,-10,null,5]
//解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
//
//
//
// 示例 2：
//
//
//输入：nums = [1,3]
//输出：[3,1]
//解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 10⁴
// -10⁴ <= nums[i] <= 10⁴
// nums 按 严格递增 顺序排列
//
//
// Related Topics 树 二叉搜索树 数组 分治 二叉树 👍 1611 👎 0
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {};
    TreeNode(int x , TreeNode* l , TreeNode* r) : val(x) , left(l) ,right(r) {};
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums){
        return handler(nums,0,nums.size() - 1);
    }
private:
    TreeNode* handler(vector<int>& nums , int left ,int right){
        if (left > right) return nullptr;

        int mid = left + (right - left)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = handler(nums,left,mid-1);
        root->right = handler(nums,mid+1,right);

        return root;
    }

};

void inorderTraversal(TreeNode* root){
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main(void){
    Solution solution;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = solution.sortedArrayToBST(nums);
    cout << "Inorder Traversal Result: ";
    inorderTraversal(root);
    cout << endl;
    
    return 0;
}

