class Solution {
public:
    int solveUsingRec(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int ans=solveUsingRec(n-1)+solveUsingRec(n-2);
        return ans;
    }
    int solveUsingMem(int n,vector<int>&dp){
        if(n==0 || n==1){
            return n;
        }
        if(dp[n] !=-1){
            return dp[n];
        }
        int ans=solveUsingMem(n-1,dp)+solveUsingMem(n-2,dp);
        dp[n]=ans;
        return dp[n];
        
    }

    int fib(int n) {
        vector<int>dp(n+1,-1);
        int ans=solveUsingMem(n,dp);
        return ans;
    }
};