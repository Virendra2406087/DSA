class Solution {
public:
    static const int mod = 1e9 + 7;
    int solveUsingRec(int n,int k, int target){
        if(n<0 || target<0){
            return 0;
        }
        if(n==0 && target==0){
            return 1;
        }
        if(n==0 && target !=0){
            return 0;
        }
        if(n !=0 && target ==0){
            return 0;
        }
        int ans=0;
        for(int value=1;value<=k;value++){
            ans=ans+solveUsingRec(n-1,k,target-value);
        }
        return ans;

    }
    int solveUsingMem(int n,int k, int target,vector<vector<long long int>> &dp){
        if(n<0 || target<0){
            return 0;
        }
        if(n==0 && target==0){
            return 1;
        }
        if(n==0 && target !=0){
            return 0;
        }
        if(n !=0 && target ==0){
            return 0;
        }
        if(dp[n][target] !=-1){
            return dp[n][target];
        }
        long long int ans=0;
        for(int value=1;value<=min(k,target);value++){
            ans = (ans + solveUsingMem(n-1, k, target-value, dp)) % mod;

        }
        dp[n][target]=ans;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,-1));
        long long int ans=solveUsingMem(n,k,target,dp);
        return ans%mod;
    }
};