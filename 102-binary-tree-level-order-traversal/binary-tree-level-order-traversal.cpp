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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);
        vector<int>level;
        while(!q.empty()){
            TreeNode* frontNode=q.front();
            q.pop();
            if(frontNode==nullptr){
                ans.push_back(level);
                level.clear();
                if(!q.empty()){
                    q.push(nullptr);
                }
            }else{
                level.push_back(frontNode->val);
                if(frontNode->left != nullptr){
                    q.push(frontNode->left);
                }
                if(frontNode->right != nullptr){
                    q.push(frontNode->right);
                }
            }
        }
        return ans;
    }
};