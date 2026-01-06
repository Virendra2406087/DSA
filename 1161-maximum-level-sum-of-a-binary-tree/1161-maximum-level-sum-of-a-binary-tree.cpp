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
    void levelOrder(TreeNode *root,vector<vector<int>>& ans) {

        
        if(root == NULL){
            return;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);  

        vector<int> level;

        while(!q.empty()) {

            TreeNode* front = q.front();
            q.pop();

            if(front == NULL) {
                ans.push_back(level);
                level.clear();

                if(!q.empty()) {
                    q.push(NULL);
                }

            } else {

                level.push_back(front->val);

                if(front->left != NULL) {
                    q.push(front->left);
                }
                if(front->right != NULL) {
                    q.push(front->right);
                }
            }
        }

        
    }

    int maxLevelSum(TreeNode* root) {
    vector<vector<int>> ans;
    levelOrder(root, ans);

    if(ans.empty()) return 0;

    int maxi = INT_MIN;
    int level = 0;

    for(int i = 0; i < ans.size(); i++){
        int sum = 0;
        for(int j = 0; j < ans[i].size(); j++){
            sum =sum+ ans[i][j];
        }

        if(sum > maxi){
            maxi = sum;
            level = i;
        }
    }

    return level + 1;
}
};