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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int l=height(root->left);
        int r=height(root->right);
        if(l==r){
            return root;
        }
        TreeNode* node;
        if(l>r){
            node=subtreeWithAllDeepest(root->left);
        }else{
            node=subtreeWithAllDeepest(root->right);
        }
        return node;
    }
};