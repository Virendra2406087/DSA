class Solution {
public:
    int solve(int n){
        if(n==0 || n==1){
            return 1;
        }
        return solve(n-1)+solve(n-2);
    }
    int solveUsingMem(int n,vector<int>&dp){
        if(n==0 || n==1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n]= solveUsingMem(n-1,dp)+solveUsingMem(n-2,dp);
        return dp[n];
    }
    int solveUsingTab(int n){
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]= dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        return solveUsingTab(n);
    }
};