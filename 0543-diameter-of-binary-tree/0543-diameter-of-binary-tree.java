/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int depth(TreeNode root){
        if(root == null){
            return 0;
        }
        int left=depth(root.left)+1;
        int right=depth(root.right)+1;
        return Math.max(left,right);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null){
            return 0;
        }
        int leftAns= diameterOfBinaryTree(root.left);
        int rightAns= diameterOfBinaryTree(root.right);
        int both=depth(root.left)+depth(root.right);
        return Math.max(both,Math.max(leftAns,rightAns));
    }
}