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
    
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder,int & preorderIndex,int inorderIndexStart,int inorderIndexEnd){
        if(preorderIndex >= preorder.size()){
            return nullptr;
        }
        if(inorderIndexStart > inorderIndexEnd){
            return nullptr;
        }
        int element=preorder[preorderIndex];
        preorderIndex++;
        TreeNode* root=new TreeNode(element);
        int elementIndexInsideInorder=getIndex(element,inorder);
        root->left=buildTree(preorder,inorder,preorderIndex,inorderIndexStart,elementIndexInsideInorder-1);
        root->right=buildTree(preorder,inorder,preorderIndex,elementIndexInsideInorder+1,inorderIndexEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex=0;
        int inorderStart=0;
        int inorderEnd=inorder.size()-1;
        TreeNode* root=buildTree(preorder,inorder,preorderIndex,inorderStart,inorderEnd);
        return root;
    }
};