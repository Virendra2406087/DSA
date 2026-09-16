class Solution {
public:
    int MOD=1000000007;
    long long solve(int n, int k,vector<vector<int>>& dp) {
        if(k == 0 || k == n) {
            return 1;
        }

        if(k > n || k < 0) {
            return 0;
        }
        if(dp[n][k] != -1){
            return dp[n][k];
        }

        dp[n][k] = (solve(n - 1, k - 1,dp) + solve(n - 1, k,dp)) % MOD;
        return dp[n][k];
    }
    int numberOfSets(int n, int k) {
        vector<vector<int>>dp(n + k, vector<int>(2 * k + 1, -1));
        return solve(n+k-1,2*k,dp);
    }
};