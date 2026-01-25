class Solution {
public:
    void dfs(int src,int dest,vector<int>& tempPaths,vector<vector<int>>&paths,vector<vector<int>>& graph){
        tempPaths.push_back(src);
        if(src==dest){
            paths.push_back(tempPaths);
            return;
        }
        for(auto nbr:graph[src]){
            dfs(nbr,dest,tempPaths,paths,graph);
            // backTracking
            tempPaths.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>tempPaths;
        vector<vector<int>>paths;
        int src=0;
        int dest=graph.size()-1;
        dfs(src,dest,tempPaths,paths,graph);
        return paths;
    }
};