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
    void solve(TreeNode root,int targetSum,int sum,List<Integer>temp,List<List<Integer>> ans) {
        if(root == null){
            return;
        }
        sum += root.val;
        temp.add(root.val);
        if(root.left == null && root.right == null){
            if(sum == targetSum){
                ans.add(new ArrayList<>(temp));
            }
        }
        solve(root.left,targetSum,sum,temp,ans);
        solve(root.right,targetSum,sum,temp,ans);
        temp.remove(temp.size()-1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<Integer>temp=new ArrayList<>();
        List<List<Integer>>ans=new ArrayList<>();
        solve(root,targetSum,0,temp,ans);
        return ans;
    }
}