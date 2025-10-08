class Solution {
public:
    int solveusingRec(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int fib=solveusingRec(n-1)+solveusingRec(n-2);
        return fib;
    }
    // top down approach
    int solveusingMem(int n,vector<int>& dp){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp[n] !=-1){
            return dp[n];
        }
        int fib=solveusingRec(n-1)+solveusingRec(n-2);
        dp[n]=fib;
        return dp[n];
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        int ans=solveusingMem(n,dp);
        return ans;
  }
};