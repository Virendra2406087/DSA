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
    int depth(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left=depth(root->left)+1;
        int right=depth(root->right)+1;
        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int option1=depth(root->left)+depth(root->right);
        int option2=diameterOfBinaryTree(root->left);
        int option3=diameterOfBinaryTree(root->right);
        return max(option1,max(option2,option3));
    }
};