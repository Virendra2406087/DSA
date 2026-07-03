class Solution {
public:
    void dfs(vector<vector<int>>& graph,int src,int target,vector<vector<int>> &ans,vector<int> &temp){
        temp.push_back(src);
        if(src==target){
            ans.push_back(temp);
        }else{
            for(int v:graph[src]){
                dfs(graph,v,target,ans,temp);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src=0;
        int n=graph.size();
        int target=n-1;
        vector<int>temp;
        vector<vector<int>>ans;
        dfs(graph,src,target,ans,temp);
        return ans;
    }
};