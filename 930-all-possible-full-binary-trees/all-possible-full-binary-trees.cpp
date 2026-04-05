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
      vector<TreeNode*> solve(int n) {
        if (n % 2 == 0){
        return {};
        } 
        if (n == 1) {
            return {new TreeNode(0)};
        }

        vector<TreeNode*> ans;
        for (int leftNodes = 1; leftNodes < n; leftNodes += 2) {
            int rightNodes = n - 1 - leftNodes;

            vector<TreeNode*> leftTrees = solve(leftNodes);
            vector<TreeNode*> rightTrees = solve(rightNodes);
            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
      vector<TreeNode*> solveUsingMem(int n,unordered_map<int, vector<TreeNode*>>& dp) {
        if (n % 2 == 0){
        return {};
        } 
        if (n == 1) {
            return {new TreeNode(0)};
        }
        if(dp.count(n)){
            return dp[n];
        }

        vector<TreeNode*> ans;
        for (int leftNodes = 1; leftNodes < n; leftNodes += 2) {
            int rightNodes = n - 1 - leftNodes;

            vector<TreeNode*> leftTrees = solveUsingMem(leftNodes,dp);
            vector<TreeNode*> rightTrees = solveUsingMem(rightNodes,dp);
            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }

        dp[n]= ans;
        return dp[n];
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> dp;
        return solveUsingMem(n,dp);
    }
};