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
    
    long SUM=0;
    long maxP=0;
    int totalSum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftSum=totalSum(root->left);
        int rightSum=totalSum(root->right);
        int sum=root->val + leftSum+rightSum;
        return sum;
    }
    int find(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftSum=find(root->left);
        int rightSum=find(root->right);
        long subTreeSum=root->val+leftSum+rightSum;
        long remainingSubTreeSum=SUM-subTreeSum;
        maxP=max(maxP,subTreeSum*remainingSubTreeSum);
        
        return subTreeSum;

    }
    int maxProduct(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        maxP=0;
        SUM=totalSum(root);
        find(root);
        return maxP%(1000000007);
    }
};