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
    bool isSame(TreeNode* leftNode,TreeNode* rightNode){
        if(leftNode==nullptr && rightNode==nullptr){
            return true;
        }
        if(leftNode==nullptr || rightNode==nullptr){
            return false;
        }
        if(leftNode->val==rightNode->val){
            bool leftAns=isSame(leftNode->left,rightNode->right);
            bool rightAns=isSame(leftNode->right,rightNode->left);
            if(leftAns==true && rightAns==true){
                return true;
            }
        }
        return false;

    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        bool ans= isSame(root->left,root->right);
      return ans;
    }
};