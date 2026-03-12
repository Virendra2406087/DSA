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
    int getHeight(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left=getHeight(root->left);
        int right=getHeight(root->right);
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        int left=getHeight(root->left);
        int right=getHeight(root->right);
        int diff=abs(left-right);
        if(diff>1){
            return false;
        }else{
            bool leftAns=isBalanced(root->left);
            bool rightAns=isBalanced(root->right);
            if(leftAns==true && rightAns==true){
                return true;
            }else{
                return false;
            }
        }


    }
};