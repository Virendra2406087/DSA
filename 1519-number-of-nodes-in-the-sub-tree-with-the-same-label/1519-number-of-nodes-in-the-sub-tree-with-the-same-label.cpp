class Solution {
public:
    void DFS(unordered_map<int,vector<int>>& adj,int curr,int parent,vector<int>& result,string &labels,vector<int>& count){
        char myLabel=labels[curr];
        int count_before_visiting_curr_children=count[myLabel-'a'];
        count[myLabel-'a']+=1;
        for(int &v:adj[curr]){
            if(v == parent){
                continue;
            }
            DFS(adj,v,curr,result,labels,count);
        }
        int count_after_visiting_curr_children=count[myLabel-'a'];
        result[curr]=count_after_visiting_curr_children-count_before_visiting_curr_children;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>>adj;
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>result(n,0);
        vector<int>count(26,0);
        DFS(adj,0,-1,result,labels,count);
        return result;
    }
};