class Solution {
public:
    void dfs(int src,unordered_map<int,vector<pair<int,int>>>& adj,vector<bool>& visited,int& result){
        visited[src]=true;
        for(auto neigh:adj[src]){
            int v=neigh.first;
            int d=neigh.second;
            result=min(result,d);
            if(!visited[v]){
                dfs(v,adj,visited,result);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto vec:roads){
            int u=vec[0];
            int v=vec[1];
            int d=vec[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        vector<bool>visited(n,false);
        int result=INT_MAX;
        int src=1;
        dfs(src,adj,visited,result);
        return result;
    }
};