class Solution {
public:
    int fibUsingRec(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int  ans=fibUsingRec(n-1)+fibUsingRec(n-2);
        return ans;
    }
    int fibUsingMem(int n,vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp[n] !=-1){
            return dp[n];
        }


        int  ans=fibUsingMem(n-1,dp)+fibUsingMem(n-2,dp);
        dp[n]=ans;
        return dp[n];
    }

    int fib(int n) {
        vector<int>dp(n+1,-1);
        int  ans=fibUsingMem(n,dp);
        return ans;
    }
};