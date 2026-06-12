class Solution {
public:
    const int MOD = 1e9 + 7;
    static const int LOG = 20;

    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    vector<int> pow2;

    void dfs(int node, int par) {
        up[node][0] = par;

        for (int j = 1; j < LOG; j++) {
            if (up[node][j - 1] != 0)
                up[node][j] = up[up[node][j - 1]][j - 1];
        }

        for (int nxt : adj[node]) {
            if (nxt == par){
               continue;
            } 
            depth[nxt] = depth[node] + 1;
            dfs(nxt, node);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]){
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = LOG - 1; j >= 0; j--) {
            if ((diff >> j) & 1){
                u = up[u][j];
            }
        }

        if (u == v){
            return u;
        }

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        adj.assign(n + 1, {});
        up.assign(n + 1, vector<int>(LOG, 0));
        depth.assign(n + 1, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1, 0);

        pow2.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (2LL * pow2[i - 1]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            int L = lca(u, v);

            int dist = depth[u] + depth[v] - 2 * depth[L];

            if (dist == 0)
                ans.push_back(0);
            else
                ans.push_back(pow2[dist - 1]);
        }

        return ans;
    }
};