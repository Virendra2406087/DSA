class Solution {
public:
    void dfs(int row,int col,vector<vector<bool>>& oceanVisited,vector<vector<int>>& heights){
        int totalRow=heights.size();
        int totalCol=heights[0].size();
        oceanVisited[row][col]=true;
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        for(int i=0;i<4;i++) {
            int newX = row + dx[i];
            int newY = col + dy[i];
            if(newX >= 0 && newY >= 0 && newX < totalRow && newY < totalCol && !oceanVisited[newX][newY] && heights[row][col] <= heights[newX][newY]) {
                dfs(newX, newY, oceanVisited, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int totalRow=heights.size();
        int totalCol=heights[0].size();
        vector<vector<bool>> pacificVisited(totalRow,vector<bool>(totalCol,false));
        vector<vector<bool>> atlanticVisited(totalRow,vector<bool>(totalCol,false));
        for(int col =0; col < totalCol ;col++) {
            dfs(0, col, pacificVisited, heights);
            dfs(totalRow-1, col, atlanticVisited, heights);
        }
        for(int row =0; row < totalRow ;row++) {
            dfs(row, 0, pacificVisited, heights);
            dfs(row, totalCol-1, atlanticVisited, heights);
        }
        vector<vector<int>>ans;
        for(int i=0;i<totalRow;i++) {
            for(int j=0;j<totalCol;j++) {
                if(pacificVisited[i][j] == 1 && atlanticVisited[i][j] == 1) {
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