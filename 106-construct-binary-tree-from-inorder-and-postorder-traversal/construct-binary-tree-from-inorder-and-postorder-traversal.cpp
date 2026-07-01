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
    int getIndex(int element,vector<int>& arr){
        for(int i=0;i<arr.size();i++){
            if(arr[i]==element){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder,int inorderStart,int inorderEnd,int& postorderIndex){
        if(postorderIndex < 0){
            return nullptr;
        }
        if(inorderStart > inorderEnd){
            return nullptr;
        }
        int element=postorder[postorderIndex];
        postorderIndex--;
        TreeNode* root=new TreeNode(element);
        int elementIndexInsideInorder=getIndex(element,inorder);
        root->right=buildTree(inorder,postorder,elementIndexInsideInorder+1,inorderEnd,postorderIndex);
        root->left=buildTree(inorder,postorder,inorderStart,elementIndexInsideInorder-1,postorderIndex);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inorderStart=0;
        int inorderEnd=inorder.size()-1;
        int postorderIndex=postorder.size()-1;
        TreeNode* root=buildTree(inorder,postorder,inorderStart,inorderEnd,postorderIndex);
        return root;
    }
};