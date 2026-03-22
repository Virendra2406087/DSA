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
    void inorderBST(TreeNode*root,vector<TreeNode*>&inorder){
        if(root==nullptr){
            return;
        }
        inorderBST(root->left,inorder);
        inorder.push_back(root);
        inorderBST(root->right,inorder);

    }
     TreeNode* build(vector<TreeNode*>& inorder, int s, int e){
        if(s > e){
            return nullptr;
        }
        int mid = s + (e - s) / 2;
        TreeNode* root = new TreeNode(inorder[mid]->val);

        root->left = build(inorder, s, mid - 1);
        root->right = build(inorder, mid + 1, e);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>inorder;
        inorderBST(root,inorder);
        int n=inorder.size();
        return build(inorder,0,n-1);
        
       
    }
};