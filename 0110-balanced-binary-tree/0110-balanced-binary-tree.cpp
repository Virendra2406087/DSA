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
    int getheight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftans=getheight(root->left);
        int rightans=getheight(root->right);
        return 1+max(leftans,rightans);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int leftheight=getheight(root->left);
        int rightheight=getheight(root->right);
        int diff=abs(rightheight-leftheight);
        if(diff>1){
            return false;
        }else{
            bool leftcheck=isBalanced(root->left);
            bool rightcheck=isBalanced(root->right);
            if(leftcheck==true && rightcheck==true){
                return true;
            }else{
                return false;
            }
        }
    }
};