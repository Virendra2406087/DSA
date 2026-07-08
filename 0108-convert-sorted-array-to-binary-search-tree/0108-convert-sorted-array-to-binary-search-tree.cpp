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
    TreeNode* solve(vector<int>& inorder,int s,int e){
        if(s>e){
            return nullptr;
        }
        int mid=s+(e-s)/2;
        int element=inorder[mid];
        TreeNode* root=new TreeNode(element);
        root->left=solve(inorder,s,mid-1);
        root->right=solve(inorder,mid+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        TreeNode* root=solve(nums,s,e);
        return root;
    }
};