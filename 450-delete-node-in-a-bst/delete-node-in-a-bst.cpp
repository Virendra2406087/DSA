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
    int getMax(TreeNode* root){
        if(root==nullptr){
            return -1;
        }
        while(root->right != nullptr){
            root=root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==key){
            // 0-child
            if(root->left == nullptr && root->right==nullptr){
                TreeNode* temp=root;
                delete temp;
                return nullptr;
            }
            // 1-child-left
            if(root->left != nullptr && root->right == nullptr){
                TreeNode* temp=root;
                TreeNode* child=root->left;
                temp->left=nullptr;
                delete temp;
                return child;
            }
            // 1-child-right
            if(root->left == nullptr && root->right != nullptr){
                TreeNode* temp=root;
                TreeNode* child=root->right;
                temp->right=nullptr;
                delete temp;
                return child;
            }
            // 2-child
            if(root->left != nullptr && root->right != nullptr){
                int replace=getMax(root->left);
                root->val=replace;
                root->left=deleteNode(root->left,replace);
                return root;
            }
        }else{
            if(key>root->val){
                root->right=deleteNode(root->right,key);
            }else{
                root->left=deleteNode(root->left,key);
            }
        }
        return root;
    }
};