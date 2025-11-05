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
    TreeNode* solve(vector<int>&inOrder,int s,int e){
        if(s>e){
            return NULL;
        }
        int mid=(s+e)/2;
        int element=inOrder[mid];
        TreeNode* root=new TreeNode(element);
        root->left=solve(inOrder,s,mid-1);
        root->right=solve(inOrder,mid+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        TreeNode* root=solve(nums,start,end);
        return root;
    }
};