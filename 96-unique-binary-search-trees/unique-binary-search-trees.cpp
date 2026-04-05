class Solution {
public:
    int solve(int start,int end){
        if(start>end){
            return 1;
        }
        int count=0;
        for(int i=start;i<=end;i++){
            int left=solve(start,i-1);
            int right=solve(i+1,end);
            count+=left*right;
        }
        return count;
    }
    int solveUsingMem(int start,int end,vector<vector<int>>&dp){
        if(start>end){
            return 1;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int count=0;
        for(int i=start;i<=end;i++){
            int left=solveUsingMem(start,i-1,dp);
            int right=solveUsingMem(i+1,end,dp);
            count+=left*right;
        }
        dp[start][end] = count;
        return dp[start][end];
    }
    int numTrees(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveUsingMem(1,n,dp);
    }
};