class Solution {
public:
    long long int mod = 1000000007;
    int solve(int n,int k,int target){
        if(n<0 || target <0){
            return 0;
        }
        if(n==0 && target==0){
            return 1;
        }
        if(n==0 && target != 0){
            return 0;
        }
        if(n !=0 && target == 0){
            return 0;
        }
        
        int ans=0;
        for(int val=0;val<=k;val++){
            ans=ans+solve(n-1,k,target-val);
        }
        return ans;
    }
    int solveUsingMem(int n,int k,int target,vector<vector<long long int>>&dp){
        if(n<0 || target <0){
            return 0;
        }
        if(n==0 && target==0){
            return 1;
        }
        if(n==0 && target != 0){
            return 0;
        }
        if(n !=0 && target == 0){
            return 0;
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        long long int ans=0;
        for(int val=1;val<=k;val++){
            ans=(ans%mod+solveUsingMem(n-1,k,target-val,dp))%mod;
        }
        dp[n][target]= ans;
        return dp[n][target];
    }
    int solveUsingTab(int n,int k,int target){
        vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,0));
        dp[0][0]=1;
        for(int d=1;d<=n;d++){
            for(int t=1;t<=target;t++){
            long long int ans=0;
        for(int val=1;val<=k;val++){
            if(t-val>=0){
                ans=(ans+dp[d-1][t-val])%mod;
            }
        }
        dp[d][t]= ans;
            }
        }
        return dp[n][target];
    }
    int solveUsingTabSO(int n,int k,int target){
        //vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,0));
        vector<int>prev(target+1,0);
        vector<int>curr(target+1,0);
        prev[0]=1;
        for(int d=1;d<=n;d++){
            for(int t=1;t<=target;t++){
            long long int ans=0;
        for(int val=1;val<=k;val++){
            if(t-val>=0){
                ans=(ans+prev[t-val])%mod;
            }
        }
        curr[t]= ans;
            }
            prev=curr;
        }
        return prev[target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,0));
        return solveUsingTabSO(n,k,target);
    }
};