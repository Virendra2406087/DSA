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
    void solve(TreeNode* root, set<int>& st) {
        if (!root) {
            return;
        } 

        st.insert(root->val);

        solve(root->left, st);
        solve(root->right, st);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> st;
        solve(root, st);

        if (st.size() < 2){
            return -1;
        }

        auto it = st.begin();
        ++it;
        return *it;
    }
};