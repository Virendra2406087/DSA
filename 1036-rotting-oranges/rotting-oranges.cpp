class Solution {
public:
    bool isSafe(int i,int j,int n,int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    int bfs(vector<vector<int>>& grid,int n,int m){
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>ans=grid;
        int minTime=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            auto frontNode=q.front();
            q.pop();
            int tempX=frontNode.first.first;
            int tempY=frontNode.first.second;
            int frontTime=frontNode.second;
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int newX=tempX+dx[i];
                int newY=tempY+dy[i];
                if(isSafe(newX,newY,n,m) && ans[newX][newY]==1){
                    q.push({{newX,newY},frontTime+1});
                    ans[newX][newY]=2;
                    minTime=max(minTime,frontTime+1);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j]==1){
                    return -1;
                }
            }
        }
        return minTime;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        return bfs(grid,n,m);
    }
};