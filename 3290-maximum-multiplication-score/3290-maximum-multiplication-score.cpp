class Solution {
public:
    long long solve(int idx, int taken,vector<int>& a,vector<int>& b) {
        if (taken == 4){
            return 0;
        } 
        if (idx == b.size()){
            return -1e18;
        } 
        long long include =1LL * a[taken] * b[idx] +solve(idx + 1, taken + 1, a, b);
        long long exclude = solve(idx + 1, taken, a, b);

        return max(include, exclude);
    }
    long long solveUsingMem(int idx, int taken,vector<int>& a,vector<int>& b,vector<vector<long long>>&dp) {
        if (taken == 4){
            return 0;
        } 
        if (idx == b.size()){
            return -1e18;
        } 
        if(dp[idx][taken] != -1){
            return dp[idx][taken];
        }
        long long include =1LL * a[taken] * b[idx] +solveUsingMem(idx + 1, taken + 1, a, b,dp);
        long long exclude = solveUsingMem(idx + 1, taken, a, b,dp);

        dp[idx][taken] =max(include, exclude);
        return dp[idx][taken];
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        int m=b.size();
        vector<vector<long long>>dp(m+1,vector<long long>(5,-1));
       return solveUsingMem(0,0,a,b,dp);

    }
};