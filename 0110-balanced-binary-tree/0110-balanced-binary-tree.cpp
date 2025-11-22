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
//  #include<climits>
class Solution {
public:
    int getHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=getHeight(root->left);
        int right=getHeight(root->right);
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int leftheight=getHeight(root->left);
        int rightheight=getHeight(root->right);
        int absdiff=abs(leftheight-rightheight);
        if(absdiff>1){
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