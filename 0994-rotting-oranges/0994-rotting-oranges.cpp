class Solution {
public:
    bool isSafe(int x,int y,int n,int m){
        return (x>=0 && x<n && y>=0 && y<m );
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>temp=grid;
        queue<pair<pair<int,int>,int>>q;
        int minTime=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j]==2){
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
            int dy[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int newX=tempX+dx[i];
                int newY=tempY+dy[i];
                if(isSafe(newX,newY,n,m) && temp[newX][newY] == 1){
                    q.push({{newX,newY},frontTime+1});
                    temp[newX][newY]=2;
                    minTime=max(minTime,frontTime+1);
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