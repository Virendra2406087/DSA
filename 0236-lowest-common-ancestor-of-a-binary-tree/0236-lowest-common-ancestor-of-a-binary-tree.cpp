/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root==p){
            return p;
        }
        if(root==q){
            return q;
        }
        TreeNode* leftTree=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightTree=lowestCommonAncestor(root->right,p,q);
        if(leftTree==NULL && rightTree==NULL){
            return NULL;
        }else if(leftTree !=NULL && rightTree==NULL){
            return leftTree;
        }else if(leftTree==NULL && rightTree !=NULL){
            return rightTree;
        }else{
            return root;
        }
    }
};