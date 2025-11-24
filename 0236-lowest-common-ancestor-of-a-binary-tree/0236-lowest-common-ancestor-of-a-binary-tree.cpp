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
        TreeNode* leftroot=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightroot=lowestCommonAncestor(root->right,p,q);
        if(leftroot ==NULL && rightroot==NULL){
            return NULL;
        }
        else if (leftroot !=NULL && rightroot==NULL){
            return leftroot;

        }
        else if(leftroot==NULL && rightroot !=NULL){
            return rightroot;
        }else{
         return root;
        }
    }
};