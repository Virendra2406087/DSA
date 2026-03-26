class Solution {
public:
    int solve(int n){
        if(n==0 || n==1){
            return n;
        }
        return solve(n-1)+solve(n-2);
    }
    int solveUsingMem(int n,vector<int>&dp){
        if(n==0 || n==1){
            return n;
        }
        if(dp[n] !=-1){
           return dp[n];
        }
        dp[n]= solveUsingMem(n-1,dp)+solveUsingMem(n-2,dp);
        return dp[n];
    }
    int solveUsingTab(int n){
        //1. 1-D dp

        vector<int>dp(n+1);
        //2. base case
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
         dp[0]=0;
         dp[1]=1;
        for(int i=2;i<=n;i++){
          int ans=dp[i-1]+dp[i-2];
          dp[i]=ans;
        }
        return dp[n];

    }
    int fib(int n) {
        int ans=solveUsingTab(n);
        return ans;
    }
};