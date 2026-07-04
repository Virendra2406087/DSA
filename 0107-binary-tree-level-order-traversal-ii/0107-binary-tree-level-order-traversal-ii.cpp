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
    void levelOrder(TreeNode* root,vector<vector<int>>& ans){
        queue<TreeNode*>q;
        vector<int>level;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front== nullptr){
                ans.push_back(level);
                level.clear();
                if(!q.empty()){
                    q.push(nullptr);
                }
            } else {
                level.push_back(front->val);
                if(front->left != nullptr){
                    q.push(front->left);
                }
                if(front->right != nullptr){
                    q.push(front->right);
                }
            }
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr){
            return ans;
        }
        levelOrder(root,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};