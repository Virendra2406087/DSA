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
    void inorder(TreeNode* root,vector<int>&ans){
        if(root==nullptr){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    void merge(vector<int>&ans1,vector<int>&ans2,vector<int>&result){
        int i=0;
        int j=0;
        while(i<ans1.size() && j<ans2.size()){
            if(ans1[i]<=ans2[j]){
               result.push_back(ans1[i++]);
            }else{
                result.push_back(ans2[j++]);
            }
        }
        while(i<ans1.size()){
            result.push_back(ans1[i++]);
        }
        while(j<ans2.size()){
            result.push_back(ans2[j++]);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1;
        vector<int>ans2;
        inorder(root1,ans1);
        inorder(root2,ans2);
        vector<int>result;
        merge(ans1,ans2,result);
        return result;
    }
};