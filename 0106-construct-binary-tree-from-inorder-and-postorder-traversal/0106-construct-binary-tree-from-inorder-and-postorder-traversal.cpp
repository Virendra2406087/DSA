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
    TreeNode* buildTree(vector<int> & inorder,vector<int>& postorder,int &postorderIndex,int inorderstart,int inorderEnd){
        if(postorderIndex<0){
            return NULL;
        }
        if(inorderstart>inorderEnd){
            return NULL;
        }
        int element=postorder[postorderIndex];
        int index=getIndex(element,inorder);
        postorderIndex--;
        TreeNode* root=new TreeNode(element);
        root->right=buildTree(inorder,postorder,postorderIndex,index+1,inorderEnd);
        root->left=buildTree(inorder,postorder,postorderIndex,inorderstart,index-1);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex=postorder.size()-1;
        int inorderstart=0;
        int inorderEnd=inorder.size()-1;
        TreeNode* root=buildTree(inorder,postorder,postorderIndex,inorderstart,inorderEnd);
        return root;
    }
};