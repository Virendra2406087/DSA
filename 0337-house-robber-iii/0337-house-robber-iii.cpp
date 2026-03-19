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
    int solve(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int includeSum=root->val;
        if(root->left){
        includeSum+=solve(root->left->left)+solve(root->left->right);
        }
        if(root->right){
        includeSum+=solve(root->right->left)+solve(root->right->right);
        }
        int excludeSum=solve(root->left)+solve(root->right);
        return max(includeSum,excludeSum);
    }
    int solveUsingMem(TreeNode* root,unordered_map<TreeNode*, int>& dp) {
        if(root==nullptr){
            return 0;
        }
        if(dp.count(root)){
            return dp[root];
        }
        int includeSum=root->val;
        if(root->left){
        includeSum+=solveUsingMem(root->left->left,dp)+solveUsingMem(root->left->right,dp);
        }
        if(root->right){
        includeSum+=solveUsingMem(root->right->left,dp)+solveUsingMem(root->right->right,dp);
        }
        int excludeSum=solveUsingMem(root->left,dp)+solveUsingMem(root->right,dp);
        dp[root]= max(includeSum,excludeSum);
        return dp[root];
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return solveUsingMem(root,dp);
    }
};