class Solution {
public:
    bool isSafe(int newX, int newY, int row, int col) {
        if(newX >= 0 && newY >= 0 && newX < row && newY < col) {
            return true;
        } else {
            return false;
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>mini;
        vector<vector<int>>diff(row,vector<int>(col,INT_MAX));
        int destX = row-1;
        int destY = col-1;
        diff[0][0]=0;
        mini.push({grid[0][0],{0,0}});
        while(!mini.empty()) {
            auto topPair = mini.top();
            mini.pop();
            int currDiff = topPair.first;
            pair<int,int> currNodeIndexPair = topPair.second;
            int currX = currNodeIndexPair.first;
            int currY = currNodeIndexPair.second;
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0; i<4; i++){
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                if(isSafe(newX,newY,row,col)) {
                    int maxDiff = max(currDiff,grid[newX][newY]);
                    if (maxDiff < diff[newX][newY]) {
                        diff[newX][newY] = maxDiff;
                        mini.push({maxDiff,{newX, newY}});
                    }
                }
            }
        }
        return diff[destX][destY];
    }
};