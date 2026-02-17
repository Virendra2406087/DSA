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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        vector<int> level;
        bool leftToRight = true;  
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front == nullptr) {

                if (!leftToRight) {
                    reverse(level.begin(), level.end());
                }

                ans.push_back(level);
                level.clear();
                leftToRight = !leftToRight;   

                if (!q.empty()) {
                    q.push(nullptr);
                }
            } else {
                level.push_back(front->val);

                if (front->left != nullptr) {
                    q.push(front->left);
                }
                if (front->right != nullptr) {
                    q.push(front->right);
                }
            }
        }
        return ans;
    }
};