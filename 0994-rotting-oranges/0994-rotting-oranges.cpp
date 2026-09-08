class Solution {
public:
    bool isSafe(int newX,int newY,int row,int col) {
        if(newX >= 0 && newY >= 0 && newX < row && newY < col) {
            return true;
        } else {
            return false;
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>temp=grid;
        int minTime=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0; i < n; i++) {
            for(int j=0; j < m; j++) {
                if(grid[i][j]==2) {
                    q.push({{i,j},0});
                }
            }
        }
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            int tempX = front.first.first;
            int tempY = front.first.second;
            int frontTime=front.second;
            for(int i=0;i<4;i++) {
                int newX = tempX + dx[i];
                int newY = tempY + dy[i];
                if(isSafe(newX,newY,n,m) && temp[newX][newY]==1) {
                    temp[newX][newY]=2;
                    q.push({{newX,newY},frontTime+1});
                    minTime = max(minTime,frontTime+1);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j]==1){
                    return -1;
                }
            }
        }
        return minTime;
    }
};