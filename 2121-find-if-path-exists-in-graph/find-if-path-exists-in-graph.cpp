class Solution {
public:
    bool check(int src,int dest,unordered_map<int,vector<int>>&adj,vector<bool>& visited){
        if(src==dest){
            return true;
        }
        if(visited[src]==true){
            return false;
        }
        visited[src]=true;
        for(auto node:adj[src]){
            if(check(node,dest,adj,visited)==true){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adj;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        return check(source,destination,adj,visited);
    }
};