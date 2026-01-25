class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>indegree;
        unordered_map<int,int>outdegree;
        for(int i=1;i<=n;i++){
            indegree[i]=0;
        }
        for(auto i:trust){
            int u=i[0];
            int v=i[1];
            indegree[v]++;
            outdegree[u]++;
        }
        for(int i=1;i<=n;i++){
            if(indegree[i]==n-1 && outdegree[i]==0){
                return i;
            }
        }
            return -1;
        
    }
};