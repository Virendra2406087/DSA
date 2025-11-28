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
    void storeInorder(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return ;
        }
        storeInorder(root->left,ans);
        ans.push_back(root->val);
        storeInorder(root->right,ans);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL ){
            return -1;
        }
        vector<int>ans;
        storeInorder(root,ans);
        return ans[k-1];

    }
};