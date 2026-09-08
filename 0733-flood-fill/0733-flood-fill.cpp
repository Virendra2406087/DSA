class Solution {
public:
    bool isSafe(int newX, int newY, int oldcolor, int row, int col,map<pair<int,int>,bool> & visited, vector<vector<int>>& ans,vector<vector<int>>& image) {
        if(newX >=0 && newY >= 0 && newX < row && newY < col && !visited[{newX,newY}] && image[newX][newY]==oldcolor) {
            return true;
        } else {
            return false;
        }
    }
    void dfs(int row,int col,int oldcolor,int newColor,vector<vector<int>>& image, int sr, int sc,map<pair<int,int>,bool> & visited, vector<vector<int>>& ans) {
        visited[{sr,sc}]=true;
        ans[sr][sc]=newColor;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newX=sr+dx[i];
            int newY=sc+dy[i];
            if(isSafe(newX, newY, oldcolor,row,col,visited,ans,image)){
                dfs(row,col,oldcolor,newColor,image,newX,newY,visited,ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row=image.size();
        int col=image[0].size();
        int oldcolor=image[sr][sc];
        int newColor=color;
        map<pair<int,int>,bool>  visited;
        vector<vector<int>> ans=image;
        dfs(row,col,oldcolor,newColor,image,sr,sc,visited,ans);
        return ans;
    }
};