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
    int solve(TreeNode* root, bool isLeft) {
        if(root == nullptr){
            return 0;
        } 

        if(root->left == nullptr && root->right == nullptr) {
            return isLeft ? root->val : 0;
        }

        return solve(root->left, true) + solve(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,false);
    }
};