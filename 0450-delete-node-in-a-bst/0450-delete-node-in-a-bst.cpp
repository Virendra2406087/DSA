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
        if(root==NULL){
            return -1;
        }
        while(root->right !=NULL){
            root=root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // case-1 zero root
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){

        
        // case-2 only root
        if(root->left == NULL && root->right == NULL){
            TreeNode* temp=root;
            delete temp;
            return NULL;
        }
        // case-3 only left child
        if(root->left !=NULL && root->right ==NULL){
            TreeNode* temp=root;
            TreeNode* child=root->left;
            temp->left=NULL;
            delete temp;
            return child;
        }
        // case-4 only right child
        if(root->left ==NULL && root->right !=NULL){
            TreeNode* temp=root;
            TreeNode* child=root->right;
            temp->right=NULL;
            delete temp;
            return child;
        }
        // case-5 two child
        if(root->left !=NULL && root->right !=NULL){
            int replaceVal=getMax(root->left);
            root->val=replaceVal;
            root->left=deleteNode(root->left,replaceVal);
            return root;
        }
        }
        else{
            if(key>root->val){
                root->right=deleteNode(root->right,key);
            }else{
                root->left=deleteNode(root->left,key);
            }
        }
       return root;
    }
};