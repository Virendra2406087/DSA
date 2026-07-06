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
    void inorderStore(TreeNode* root,vector<int>& ans){
        if(root==nullptr){
            return;
        }
        inorderStore(root->left,ans);
        ans.push_back(root->val);
        inorderStore(root->right,ans);
    }
    bool check(vector<int>& ans,int k){
        int n=ans.size();
        int i=0,j=n-1;
        while(i<j){
            int sum=ans[i]+ans[j];
            if(sum == k){
                return true;
            }
            if(sum > k){
                j--;
            }
            if(sum < k){
                i++;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        inorderStore(root,ans);
        return check(ans,k);
    }
};