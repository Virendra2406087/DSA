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
class Info{
    public:
    int minVal;
    int maxVal;
    int sum;
    bool isBST;
};
class Solution {
public:
   Info solve(TreeNode* root,int& sum){
    if(root==nullptr){
        Info temp;
        temp.minVal=INT_MAX;
        temp.maxVal=INT_MIN;
        temp.sum=0;
        temp.isBST=true;
        return temp;
    }
    // LRN
    Info leftAns= solve(root->left,sum);
    Info rightAns= solve(root->right,sum);
    // N
    Info currAns;
    currAns.minVal=min(root->val,min(leftAns.minVal,rightAns.minVal));
    currAns.maxVal=max(root->val,max(leftAns.maxVal,rightAns.maxVal));
    currAns.sum=root->val+leftAns.sum+rightAns.sum;
    if(root->val > leftAns.maxVal && root->val < rightAns.minVal && leftAns.isBST && rightAns.isBST){
        currAns.isBST=true;
        sum=max(sum,currAns.sum);
    }else{
        currAns.isBST=false;
    }
    return currAns;
   }
    
    int maxSumBST(TreeNode* root) {
        int sum=0;
        Info ans= solve(root,sum);
        return sum;
    }
};