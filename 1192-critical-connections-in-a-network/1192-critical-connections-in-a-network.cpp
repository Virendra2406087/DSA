class Solution {
public:
    void countBridge(int src,int parent,unordered_map<int,list<int>>& adjList, unordered_map<int,bool>& visited,vector<int>& tin, vector<int>& low,int timer,vector<vector<int>>& ans) {
        visited[src]=true;
        tin[src]=low[src]=timer++;
        for(auto nbr : adjList[src]) {
            if(nbr == parent) {
                continue;
            } else if(! visited[nbr]) {
                countBridge(nbr,src,adjList,visited,tin,low,timer,ans);
                low[src]=min(low[nbr],low[src]);
                if(low[nbr] > tin[src]) {
                    vector<int>temp;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }
            } else {
                low[src]=min(low[src],low[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>>adjList;
        for(auto i:connections) {
            int u = i[0];
            int v = i[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int src=0;
        int parent=-1;
        unordered_map<int,bool> visited;
        vector<int> tin(n);
        vector<int> low(n);
        int timer=0;
        vector<vector<int>> ans;
        countBridge(src, parent, adjList, visited, tin, low, timer,ans);
        return ans;
    }
};