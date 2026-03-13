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
    int getIndex(int element,vector<int>&arr){
        for(int i=0;i<arr.size();i++){
            if(arr[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int &preorderIndex,int inorderstart,int inorderend){
        if(inorderstart>inorderend){
            return nullptr;
        }
        if(preorderIndex>=preorder.size()){
            return nullptr;
        }
        int element=preorder[preorderIndex];
        preorderIndex++;
        TreeNode* root=new TreeNode(element);
        int elementIndex=getIndex(element,inorder);
        root->left=build(preorder,inorder,preorderIndex,inorderstart,elementIndex-1);
        root->right=build(preorder,inorder,preorderIndex,elementIndex+1,inorderend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex=0;
        int inorderstart=0;
        int inorderend=inorder.size()-1;
        TreeNode* root=build(preorder,inorder,preorderIndex,inorderstart,inorderend);
        return root;
    }
};