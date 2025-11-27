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
    TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder,int &postorderIndex,int inorderstart,int inorderend){
        if(postorderIndex<0){
            return NULL;
        }
        if(inorderstart>inorderend){
            return NULL;
        }
        int element=postorder[postorderIndex];
        postorderIndex--;
        TreeNode* root=new TreeNode(element);
        int elementIndex=getIndex(element,inorder);
        root->right=buildTree(inorder,postorder,postorderIndex,elementIndex+1,inorderend);
        root->left=buildTree(inorder,postorder,postorderIndex,inorderstart,elementIndex-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inorderstart=0;
        int inorderend=inorder.size()-1;
        int postorderIndex=postorder.size()-1;
        TreeNode* root=buildTree(inorder,postorder,postorderIndex,inorderstart,inorderend);
        return root;
    }
};