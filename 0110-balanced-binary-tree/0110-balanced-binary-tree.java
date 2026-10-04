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
        if(root==null){
            return 0;
        }
        int leftans=depth(root.left)+1;
        int rightans=depth(root.right)+1;
        return Math.max(leftans,rightans);
    }
    public boolean isBalanced(TreeNode root) {
        if(root==null){
            return true;
        }
        int leftans=depth(root.left);
        int rightans=depth(root.right);
        int diff=Math.abs(leftans-rightans);
        if(diff > 1){
            return false;
        } else {
            boolean left=isBalanced(root.left);
            boolean right=isBalanced(root.right);
            if(left == true && right == true){
                return true;
            } else {
                return false;
            }
        }

    }
}