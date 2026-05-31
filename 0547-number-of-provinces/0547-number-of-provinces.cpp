class Solution {
public:
    void dfs(int src,unordered_map<int,bool>& visited,int n,vector<vector<int>>& isConnected){
        visited[src]=1;
        int col=n;
        int row=src;
        for(int nbr=0;nbr<col;nbr++){
           int nb=nbr;
           if(src != nb && isConnected[row][nbr] == 1){
              if(! visited[nb]){
                dfs(nb,visited,n,isConnected);
              }
           }                                           
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool>visited;
        int n=isConnected.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(! visited[i]){
                dfs(i,visited,n,isConnected);
                count++;
            }
        }
     return count;
    }
};