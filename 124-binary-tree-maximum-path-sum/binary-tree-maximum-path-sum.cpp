/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum;
    int solve(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int l=solve(root->left);
        int r=solve(root->right);
        int koi_neech_milega=l+r+root->val;
        int only_root=root->val;
        int koi_ek=max(r,l)+root->val;
        maxSum=max({maxSum,koi_neech_milega,only_root,koi_ek});
        return max(koi_ek,only_root);
    }
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};