#include <vector>
#include "TreeNode_CPP.h"
using namespace std;

class First {

public:

    TreeNode* sortedArrayToBST(vector<int>& nums){
        return helper(nums,0,nums.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& nums , int first , int last){
        if (first > last){
            return nullptr;
        }

        int mid = first + (last - first) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = helper(nums,first,mid-1);
        root->right = helper(nums,mid+1,last);

        return root;
    }
};

//Apr 2 7:00AM

class Second {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        // 总是选择中间位置左边的数字作为根节点
        int mid = (left + right) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};


int main(){

    vector<int> nums = {-10, -3, 0, 5, 9};
    First f ;
    TreeNode* root = f.sortedArrayToBST(nums);

    return 0;
}
