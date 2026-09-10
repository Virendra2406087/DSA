class Solution {
public:
    void dfs(int src, int dest, vector<int>& temp, vector<vector<int>>& ans, vector<vector<int>>& graph) {
        temp.push_back(src);
        if(src == dest) {
            ans.push_back(temp);
            return;
        }
        for(auto nbr : graph[src]) {
            dfs(nbr, dest, temp, ans, graph);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0;
        int dest = graph.size() - 1;
        vector<int> temp; 
        vector<vector<int>> ans;
        dfs(src,dest,temp,ans,graph);
        return ans;
    }
};