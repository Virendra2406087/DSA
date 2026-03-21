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
    bool valid(TreeNode* root,TreeNode* min,TreeNode* max){
        if(root==nullptr){
          return true;
        }
        if(min !=nullptr && root->val <= min->val){
          return false;
        }
        if(max !=nullptr && root->val >= max->val){
          return false;
        }
        bool left=valid(root->left,min,root);
        bool right=valid(root->right,root,max);
        return left&&right;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* min=nullptr;
        TreeNode* max=nullptr;
        bool ans=valid(root,min,max);
        return ans;
    }
};