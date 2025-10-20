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
    bool solve(TreeNode* root,int targetSum,int sum){
        if(root==NULL){
            return false;
        }
        sum=sum+root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                return true;
            }else {
                return false;
            }
        }
            bool leftans=solve(root->left,targetSum,sum);
            bool rightans=solve(root->right,targetSum,sum);

        
        return leftans || rightans;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool ans=solve(root,targetSum,sum);
        return ans;
    }
};