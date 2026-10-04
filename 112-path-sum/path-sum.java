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
    boolean solve(TreeNode root,int targetSum,int sum){
        if(root == null){
            return false;
        }
        sum += root.val;
        if(root.left == null && root.right == null){
            if(sum == targetSum){
                return true;
            } else {
                return false;
            }
        }
        boolean leftSum = solve(root.left,targetSum,sum);
        boolean rightSum = solve(root.right,targetSum,sum);
        return leftSum || rightSum;

    }
    public boolean hasPathSum(TreeNode root, int targetSum) {
        return solve(root,targetSum,0);
    }
}