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
    void solve(TreeNode* root,int target,int sum,vector<int>& temp,vector<vector<int>>&ans){
        if(root==nullptr){
            return;
        }
        sum=sum+root->val;
        temp.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(sum==target){
                ans.push_back(temp);
                temp.pop_back();
                return;
            }
        }
        solve(root->left,target,sum,temp,ans);
        solve(root->right,target,sum,temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        vector<vector<int>>ans;
        int sum=0;
        solve(root,targetSum,sum,temp,ans);
        return ans;
    }
};