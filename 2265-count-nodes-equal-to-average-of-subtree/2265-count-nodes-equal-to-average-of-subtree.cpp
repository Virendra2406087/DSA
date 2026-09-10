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
    int ans=0;
    pair<int,int> dfs(TreeNode * root) {
        if(root==nullptr) {
            return {0,0};
        }
        pair<int,int>leftAns = dfs(root->left);
        pair<int,int>rightAns = dfs(root->right);
        int sum = root->val + leftAns.first + rightAns.first;
        int count = 1 + leftAns.second + rightAns.second;
        int average = sum / count;
        if(root->val == average) {
            ans++;
        } 
        return {sum,count};
        
    } 
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};