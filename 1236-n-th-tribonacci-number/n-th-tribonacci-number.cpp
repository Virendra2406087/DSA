class Solution {
public:
    int solve(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 1;
        }
        int ans=solve(n-1)+solve(n-2)+solve(n-3);
        return ans;
    }
    int solveMem(int n,vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n]=solveMem(n-1,dp)+solveMem(n-2,dp)+solveMem(n-3,dp);
        return dp[n];
    }
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        int ans=solveMem(n,dp);
        return ans;
    }
};