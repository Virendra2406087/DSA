class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);

        vector<int> last(26, -1), p(n, -1), old(n, -1);
        vector<int> order;

        // Iterative DFS
        vector<pair<int,int>> st;
        st.push_back({0, 0});

        while (!st.empty()) {
            auto [u, state] = st.back();
            st.pop_back();

            int c = s[u] - 'a';

            if (state == 0) {
                old[u] = last[c];

                if (u != 0)
                    p[u] = (last[c] == -1 ? parent[u] : last[c]);

                last[c] = u;
                order.push_back(u);

                st.push_back({u, 1});

                for (int v : adj[u])
                    st.push_back({v, 0});
            }
            else {
                last[c] = old[u];
            }
        }

        // Calculate subtree sizes
        vector<int> ans(n, 1);

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            ans[p[u]] += ans[u];
        }

        return ans;
    }
};