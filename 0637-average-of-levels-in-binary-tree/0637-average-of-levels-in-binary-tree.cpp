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
    void levelOrder(TreeNode* root,vector<vector<int>>& ans){
        if(root==NULL){
            return ;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>level;
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                ans.push_back(level);
                level.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                level.push_back(front->val);
                if(front->left != NULL){
                    q.push(front->left);
                }
                if(front->right !=NULL){
                    q.push(front->right);
                }
            }
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>>ans;
        levelOrder(root,ans);
        int n=ans.size();
        vector<double>avg;
        for(int i=0;i<n;i++){
        int m=ans[i].size();
            long long sum=0;
            for(int j=0;j<m;j++){
               sum=sum+ans[i][j];
            }
          double average=(double)sum/m;
          avg.push_back(average);
        }
        return avg;
    }
};