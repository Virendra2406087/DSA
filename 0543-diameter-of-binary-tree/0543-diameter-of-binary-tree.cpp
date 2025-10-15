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
        int leftans=maxDepth(root->left)+1;
        int rightans=maxDepth(root->right)+1;
        return max(leftans,rightans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return -0;
        }
        int option1=maxDepth(root->right)+maxDepth(root->left);
        int option2=diameterOfBinaryTree(root->left);
        int option3=diameterOfBinaryTree(root->right);
        int ans=max(option1,max(option2,option3));
        return ans;
    }
};