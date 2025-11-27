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
    void inorder(TreeNode* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        vector<int>ans;
        inorder(root,ans);
        int s=0;
        int e=ans.size()-1;
        while(s<e){
            int sum=ans[s]+ans[e];
            if(sum==k){
                return true;
            }else{
                if(sum>k){
                    e--;
                }
                if(sum<k){
                    s++;
                }
            }
        }
        return false;
    }
};