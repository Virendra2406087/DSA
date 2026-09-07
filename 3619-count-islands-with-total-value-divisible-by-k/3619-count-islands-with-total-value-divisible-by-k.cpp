class Solution {
public:
    
    bool isSafe(int newX,int newY,int row,int col,vector<vector<int>>& grid,vector<vector<bool>>& visited) {
        if(newX>=0 && newY >= 0 && newX < row && newY < col && !visited[newX][newY] && grid[newX][newY] > 0) {
            return true;
        } else {
            return false;
        }
    }
    long long dfs(int i,int j,int row,int col,vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        visited[i][j]=true;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        long long sum = grid[i][j];
        for(int k=0;k<4;k++){
            int newX=i+dx[k];
            int newY=j+dy[k];
            if(isSafe(newX,newY,row,col,grid,visited)){
                sum +=dfs(newX,newY,row,col,grid,visited);
            }
        }
        return sum;
    }
    
    int countIslands(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        long long ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!visited[i][j] && grid[i][j] > 0){
                    long long area = dfs(i,j,row,col,grid,visited);
                    if(area % k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};