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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // map<col, map<row, multiset<values>>>
        map<int, map<int, multiset<int>>> distMap;

        queue<tuple<TreeNode*, int, int>> q;     // node, hd, level
        q.push({root, 0, 0});

        int minDist = INT_MAX, maxDist = INT_MIN;

        while (!q.empty()) {
            auto [node, hd, lvl] = q.front();
            q.pop();

            minDist = min(minDist, hd);
            maxDist = max(maxDist, hd);

            distMap[hd][lvl].insert(node->val);

            if (node->left) {
                q.push({node->left, hd - 1, lvl + 1});
            }
            if (node->right) {
                q.push({node->right, hd + 1, lvl + 1});
            }
        }

        vector<vector<int>> ans;

        for (int col = minDist; col <= maxDist; col++) {
            vector<int> temp;
            for (auto &rowSet : distMap[col]) {
                temp.insert(temp.end(), rowSet.second.begin(), rowSet.second.end());
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
