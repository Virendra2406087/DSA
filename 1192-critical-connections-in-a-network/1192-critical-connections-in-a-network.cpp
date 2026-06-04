class Solution {
public:
    void countBridge(int src,int parent,vector<int>& tin,vector<int>& low,vector<bool>& visited,int& timer,vector<vector<int>>& ans,vector<vector<int>>& adj) {

        visited[src] = true;
        tin[src] = low[src] = timer++;

        for (auto nbr : adj[src]) {

            if (nbr == parent){
                continue;
            }

            if (!visited[nbr]) {
                countBridge(nbr, src, tin, low,visited, timer, ans, adj);
                low[src] = min(low[src], low[nbr]);
                if (low[nbr] > tin[src]) {
                    ans.push_back({src, nbr});
                }
            } else {
                low[src] = min(low[src], tin[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n,vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<bool> visited(n, false);

        vector<vector<int>> ans;
        int timer = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                countBridge(i, -1, tin, low,visited, timer, ans, adj);
            }
        }

        return ans;
    }
};