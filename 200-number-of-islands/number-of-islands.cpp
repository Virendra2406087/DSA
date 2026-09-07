class Solution {
public:
    bool isSafe(int newX,int newY,int row,int col,vector<vector<char>>& grid,map<pair<int,int>,bool>& visited) {
        if(newX>=0 && newY >= 0 && newX < row && newY < col && !visited[{newX,newY}] && grid[newX][newY]=='1') {
            return true;
        } else {
            return false;
        }
    }
    void solveUsingBFS(int i, int j ,int row, int col, vector<vector<char>>& grid, map<pair<int,int>,bool>& visited) {
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[{i,j}]=true;
        while(!q.empty()) {
            auto frontEle = q.front();
            q.pop();
            int tempX = frontEle.first;
            int tempY = frontEle.second;
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int newX=tempX + dx[i];
                int newY=tempY + dy[i];
                if(isSafe(newX,newY,row,col,grid,visited)) {
                    q.push({newX,newY});
                    visited[{newX,newY}]=true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        map<pair<int,int>,bool> visited;
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!visited[{i,j}] && grid[i][j]=='1'){
                    solveUsingBFS(i,j,row,col,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};