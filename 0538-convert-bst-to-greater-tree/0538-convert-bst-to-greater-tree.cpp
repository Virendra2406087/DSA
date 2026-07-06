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
    void inorderStore(TreeNode* root,vector<int>& ans){
        if(root==nullptr){
            return;
        }
        inorderStore(root->left,ans);
        ans.push_back(root->val);
        inorderStore(root->right,ans);
    }
    void updateTree(TreeNode* root,vector<int>& ans,int &index){
        if(root==nullptr){
            return;
        }
        updateTree(root->left,ans,index);
        root->val=ans[index];
        index++;
        updateTree(root->right,ans,index);
    }

    TreeNode* convertBST(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        if(root->left == nullptr && root->right == nullptr){
            return root;
        }
        vector<int>ans;
        inorderStore(root,ans);
        int n=ans.size();
        for(int i=n-1;i>=0;i--){
            int currVal=ans[i];
            int nextVal=0;
            if(i+1 < n){
                nextVal=ans[i+1];
            }
            int sum=currVal+nextVal;
            ans[i]=sum;
        }
        int index=0;
        updateTree(root,ans,index);
        return root;
    }
};