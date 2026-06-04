class Solution {
public:
    int solve(int i,int j,int m,int n){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i<0 || i>=m || j<0 || j>=n){
            return 0;
        }
        int right=solve(i,j+1,m,n);
        int down=solve(i+1,j,m,n);
        return right+down;
    }
    int solveMem(int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i<0 || i>=m || j<0 || j>=n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right=solveMem(i,j+1,m,n,dp);
        int down=solveMem(i+1,j,m,n,dp);
        dp[i][j]= right+down;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solveMem(0,0,m,n,dp);
    }
};