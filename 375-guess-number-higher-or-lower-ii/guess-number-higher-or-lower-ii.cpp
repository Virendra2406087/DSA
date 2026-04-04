class Solution {
public:
    int solve(int start,int end){
        if(start>=end){
            return 0;
        }
        int ans=INT_MAX;
        for(int i=start;i<=end;i++){
           ans=min(ans,i+max(solve(start,i-1),solve(i+1,end)));
        }
        return ans;
    }
    int solveUsingMem(int start,int end,vector<vector<int>>&dp){
        if(start>=end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int ans=INT_MAX;
        for(int i=start;i<=end;i++){
           ans=min(ans,i+max(solveUsingMem(start,i-1,dp),solveUsingMem(i+1,end,dp)));
        }
        dp[start][end]= ans;
        return dp[start][end];
    }
    int solveUsingTab(int n){
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    for(int len = 2; len <= n; len++){
        for(int start = 1; start <= n - len + 1; start++){
            int end = start + len - 1;
            int ans = INT_MAX;

            for(int i = start; i <= end; i++){
                ans = min(ans, i + max(dp[start][i-1], dp[i+1][end]));
            }

            dp[start][end] = ans;
        }
    }

    return dp[1][n];
}
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveUsingTab(n);
    }
};