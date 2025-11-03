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
    void inorderstore(TreeNode* root,vector<int>&inorder){
       if(root ==NULL){
          return;
       }
        inorderstore(root->left,inorder);
        inorder.push_back(root->val);
        inorderstore(root->right,inorder);
    }
    bool checkTarget(vector<int>& arr,int target){
        int n=arr.size();
        int s=0;
        int e=n-1;
        while(s<e){
            int sum=arr[s]+arr[e];
            if(sum==target){
                return true;
            }
            if(sum<target){
                s++;
            }
            if(sum>target){
                e--;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        inorderstore(root,inorder);
        bool ans=checkTarget(inorder,k);
        return ans;
    }
};