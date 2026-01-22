class Solution {
public:
   bool isSafe(int i,int j,int oldColor,vector<vector<int>>& image,vector<vector<int>>& ans,map<pair<int,int>,bool>& visited){
    if(i>=0 && i<image.size() && j>=0 && j<image[0].size() && ans[i][j]==oldColor && !visited[{i,j}]){
        return 1;
    }
    return 0;
   }
   void dfs(int oldColor,int newColor,map<pair<int,int>,bool>& visited,vector<vector<int>>& ans,vector<vector<int>>& image,int sr,int sc){
    visited[{sr,sc}]=1;
    ans[sr][sc]=newColor;
    int dx[]={-1,0,1,0};
    int dy[]={0,-1,0,1};
    for(int i=0;i<4;i++){
        int newX=sr+dx[i];
        int newY=sc+dy[i];
        if(isSafe(newX,newY,oldColor,image,ans,visited)){
            dfs(oldColor,newColor,visited,ans,image,newX,newY);
        }
    }
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int oldColor=image[sr][sc];
        int newColor=color;
        if(oldColor==color){
            return image;
        }
        map<pair<int,int>,bool>visited;
        dfs(oldColor,newColor,visited,ans,image,sr,sc);
        return ans;
    }
};