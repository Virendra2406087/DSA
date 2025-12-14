class Solution {
public:
    int solveUsingRec(int n){
        if(n==0 || n==1){
            return n;
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
    int solveUsingTab(int n){
        vector<int>dp(n+1,-1);
        if(n==0 || n==1){
            return n;
        }
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int ans=dp[i-1]+dp[i-2];
            dp[i]=ans;
        }
        return dp[n];
        
    }
    int solveUsingTabSO(int n){
        // vector<int>dp(n+1,-1);
        if(n==0 || n==1){
            return n;
        }
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
        // vector<int>dp(n+1,-1);
        int ans=solveUsingTabSO(n);
        return ans;
    }
};