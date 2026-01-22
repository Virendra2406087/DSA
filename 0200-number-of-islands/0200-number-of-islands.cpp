class Solution {
public:
    bool isSafe(int i,int j,vector<vector<char>>& grid,map<pair<int,int>,bool>& visited){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1' && !visited[{i,j}]){
            return true;
        }return false;
    }
    void bfs(int i,int j,vector<vector<char>>& grid,map<pair<int,int>,bool>& visited){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[{i,j}]=true;
        while(!q.empty()){
            auto frontNode=q.front();
            q.pop();
            int tempX=frontNode.first;
            int tempY=frontNode.second;
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int newX=tempX+dx[k];
                int newY=tempY+dy[k];
                if(isSafe(newX,newY,grid,visited)){
                    q.push({newX,newY});
                    visited[{newX,newY}]=true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        map<pair<int,int>,bool>visited;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[{i,j}] && grid[i][j]=='1'){
                    bfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};