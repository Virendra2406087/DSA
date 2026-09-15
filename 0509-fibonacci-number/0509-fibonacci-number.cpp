class Solution {
public:
    int solve(int n){
        if(n==1 || n==0){
            return n;
        }
        return solve(n-1)+solve(n-2);
    }
    int solveUsingMem(int n,vector<int>& dp){
        if(n==1 || n==0){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] =solveUsingMem(n-1,dp)+solveUsingMem(n-2,dp);
        return dp[n];
    }
    int solveUsingTab(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i] =dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int solveUsingTabSO(int n){
        int prev2=0;
        int prev1=1;
        int curr=-1;
        for(int i=2;i<=n;i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }

    int fib(int n) {
        vector<int>dp(n+1,-1);
        return solveUsingTab(n);
    }
};