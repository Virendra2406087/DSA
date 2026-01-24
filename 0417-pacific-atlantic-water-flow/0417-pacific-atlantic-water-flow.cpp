class Solution {
public:
    void dfs(int row,int col,vector<vector<bool>>& oceanVisited,vector<vector<int>>& heights){
        int totalRows=heights.size();
        int totalCols=heights[0].size();
        oceanVisited[row][col]=1;
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        for(int i=0;i<4;i++){
            int newX=row+dx[i];
            int newY=col+dy[i];
            if(newX>=0 && newX<totalRows && newY>=0 && newY<totalCols && oceanVisited[newX][newY]==false && heights[row][col]<=heights[newX][newY]){
                dfs(newX,newY,oceanVisited,heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int totalRows=heights.size();
        int totalCols=heights[0].size();
        vector<vector<bool>>pacificVisited(totalRows,vector<bool>(totalCols,0));
        vector<vector<bool>>atlanticVisited(totalRows,vector<bool>(totalCols,0));
        for(int col=0;col<totalCols;col++){
            dfs(0,col,pacificVisited,heights);
            dfs(totalRows-1,col,atlanticVisited,heights);
        }
        for(int row=0;row<totalRows;row++){
            dfs(row,0,pacificVisited,heights);
            dfs(row,totalCols-1,atlanticVisited,heights);
        }
        // intersection 
        vector<vector<int>>ans;
        for(int i=0;i<totalRows;i++){
            for(int j=0;j<totalCols;j++){
                if(pacificVisited[i][j]==1 && atlanticVisited[i][j]==1){
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};