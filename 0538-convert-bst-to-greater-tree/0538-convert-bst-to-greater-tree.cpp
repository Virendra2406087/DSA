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
    void inorderstore(TreeNode* root,vector<int>&inOrder){
        if(root==NULL){
            return;
        }
        inorderstore(root->left,inOrder);
        inOrder.push_back(root->val);
        inorderstore(root->right,inOrder);
        return;
    }
    void updateTree(TreeNode* root,vector<int>&inOrder,int &index){
        if(root==NULL){
            return;
        }
        updateTree(root->left,inOrder,index);
        root->val=inOrder[index];
        index++;
        updateTree(root->right,inOrder,index);
        return;
    }
    TreeNode* convertBST(TreeNode* root) {
         if(root==NULL){
            return NULL;
        }
        if(root->left ==NULL && root->right ==NULL){
            return root;
        }
        vector<int>inOrder;
        inorderstore(root,inOrder);
        int n=inOrder.size();
        for(int i=n-1;i>=0;i--){
            int currVal=inOrder[i];
            int nextVal=0;
            if(i+1<n){
                nextVal=inOrder[i+1];
            }
            int sum=currVal+nextVal;
            inOrder[i]=sum;
        }
        int index=0;
        updateTree(root,inOrder,index);
        return root;
    }
};