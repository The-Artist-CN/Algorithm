#include <vector>
#include "TreeNode_CPP.h"
using namespace std;

class Solution {

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

int main(){

    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution solution;
    TreeNode* root = solution.sortedArrayToBST(nums);

    return 0;
}
