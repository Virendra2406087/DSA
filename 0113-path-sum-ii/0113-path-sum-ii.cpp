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
    void solve(TreeNode* root,int targetSum,int sum,vector<int>&temp,vector<vector<int>>& ans){
        if(root==NULL){
            return ;
        }
        sum=sum+root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                ans.push_back(temp);
                // temp.pop_back();
            }
        }
        solve(root->left,targetSum,sum,temp,ans);
        solve(root->right,targetSum,sum,temp,ans);

        
        temp.pop_back();
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        int sum=0;
        vector<vector<int>>ans;
        vector<int>temp;
        solve(root,targetSum,sum,temp,ans);
        return ans;
        
    }
};