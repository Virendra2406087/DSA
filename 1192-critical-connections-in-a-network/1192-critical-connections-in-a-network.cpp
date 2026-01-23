class Solution {
public:
    void CountBridge(int src,int parent,vector<int>& tin,vector<int>& low,unordered_map<int,bool>& visited,int timer,vector<vector<int>>& ans,unordered_map<int,list<int>>& adj){
        timer++;
        visited[src]=true;
        tin[src]=timer;
        low[src]=timer;
        for(auto nbr : adj[src]){
           if(nbr==parent){
            continue;
           }else if(!visited[nbr]){
            CountBridge(nbr,src,tin,low,visited,timer,ans,adj);
            low[src]=min(low[src],low[nbr]);
            if(low[nbr]>tin[src]){
                vector<int>temp;
                temp.push_back(src);
                temp.push_back(nbr);
                ans.push_back(temp);
            }
           }else{
            low[src]=min(low[src],low[nbr]);
           }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>ans;
        int timer=0;
        int src=0;
        int parent=-1;
        vector<int>tin(n);
        vector<int>low(n);
        unordered_map<int,bool>visited;
        unordered_map<int,list<int>>adj;
        for(auto i:connections){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        CountBridge(src,parent,tin,low,visited,timer,ans,adj);
        return ans;
        
    }
};