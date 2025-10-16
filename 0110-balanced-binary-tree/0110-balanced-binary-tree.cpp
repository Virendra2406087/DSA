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
    int maxDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftans=maxDepth(root->left);
        int rightans=maxDepth(root->right);
        int ans=max(leftans,rightans)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int leftans=maxDepth(root->left);
        int rightans=maxDepth(root->right);
        int ans=abs(leftans-rightans);
        if(ans>1){
            return false;
        }else{
            bool leftb=isBalanced(root->left);
            bool rightb=isBalanced(root->right);
            if(leftb==true && rightb==true){
                return true;
            }else{
               return false;
            }
        }
    }
};