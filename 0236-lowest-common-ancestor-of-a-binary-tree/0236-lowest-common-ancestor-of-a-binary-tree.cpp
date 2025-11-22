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
        if(root== NULL){
            return NULL;
        }
        if(root == p){
            return p;
        }
        if(root == q){
            return q;
        }
        TreeNode* lefttree=lowestCommonAncestor(root->left,p,q);
        TreeNode* righttree=lowestCommonAncestor(root->right,p,q);
        if(lefttree==NULL && righttree==NULL){
            return NULL;
        }
        if(lefttree==NULL && righttree !=NULL){
            return righttree;
        }
        if(lefttree !=NULL && righttree==NULL){
            return lefttree;
        }else{
            return root;
        }
    }
};