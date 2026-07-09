class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> root(n);

        for (int i = 0; i < n; i++) {
            root[i] = i;
        }

        int start = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                root[i] = start;
            } else {
                start = i;
            }
        }

        vector<bool> ans;
        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];
            ans.push_back(root[u] == root[v]);
        }

        return ans;
    }
};