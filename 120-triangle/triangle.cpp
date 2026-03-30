class Solution {
public:
    int solve(vector<vector<int>>&triangle,int i,int j){
        if(i==triangle.size()-1){
           return triangle[i][j];
        }
        int down = solve(triangle, i + 1, j);
        int diag = solve(triangle, i + 1, j + 1);
        return triangle[i][j] + min(down, diag);
    }
    int solveUsingMem(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){
        
        if(i == triangle.size() - 1){
            return dp[i][j] = triangle[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int down = solveUsingMem(triangle, i + 1, j, dp);
        int diag = solveUsingMem(triangle, i + 1, j + 1, dp);

        return dp[i][j] = triangle[i][j] + min(down, diag);
    }
    int solveUsingTab(vector<vector<int>>&triangle){
        int n=triangle.size();
        vector<vector<int>> dp(n);
        for(int i = 0; i < n; i++){
            dp[i] = vector<int>(triangle[i].size(), -1);
        }
        for(int j = 0; j < triangle[n-1].size(); j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n);
        for(int i = 0; i < n; i++){
            dp[i] = vector<int>(triangle[i].size(), -1);
        }
        return solveUsingTab(triangle);
    }
};