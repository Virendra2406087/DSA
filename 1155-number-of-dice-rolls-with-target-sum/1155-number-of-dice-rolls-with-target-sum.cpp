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
    int solveUsingTab(int n,int k,int target){
        vector<vector<long long>>dp(n+1,vector<long long>(target+1,0));
        dp[0][0]=1;
        for(int a=1;a<=n;a++){
            for(int t=1;t<=target;t++){
                long long ans=0;
                for(int value=1;value<=min(k,target);value++){
                    long long temp=0;
                    if(t-value >=0){
                        temp=dp[a-1][t-value]%mod;
                    }
                    ans=(ans%mod+temp)%mod;
                }
                dp[a][t]=ans;
            }
        }
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,-1));
        long long int ans=solveUsingTab(n,k,target);
        return ans%mod;
    }
};