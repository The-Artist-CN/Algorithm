



class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(){};
    TreeNode(int val){
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

public class Solution {
    public static void main(String[] args){
        int[] nums = {1,2,3,4,5,6,7,8,9};
        Solution solution = new Solution();
        TreeNode root = solution.sortArrayToBST(nums);
        System.out.println(root);
    }

    public TreeNode sortArrayToBST(int[] nums){
        TreeNode root = inorder(nums,0,nums.length-1);
        return root;
    }

    private TreeNode inorder(int[] nums, int start , int end){
        if (start > end) return null;
        int mid  = start + (end - start) / 2;
        TreeNode root = new  TreeNode(nums[mid]); 
        root.left = inorder(nums,start,mid -1);
        root.right = inorder(nums,mid+1,end);
        return root;
    }
}
