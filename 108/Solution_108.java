



public class Solution_108 {

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
