/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null){
            return null;
        }
        if(root == p){
            return p;
        }
        if(root==q){
            return q;
        }
        TreeNode leftAns = lowestCommonAncestor(root.left,p,q);
        TreeNode rightAns = lowestCommonAncestor(root.right,p,q);
        if(leftAns == null && rightAns == null){
            return null;
        } else if(leftAns != null && rightAns == null){
            return leftAns;
        } else if(leftAns == null && rightAns != null){
            return rightAns;
        } else {
            return root;
        }
    }
}