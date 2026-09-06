class Solution {
public:
    int solve(string &s,string &t,int i,int j){
        int n=s.size();
        int m=t.size();
        if(j == m) {
            return 1;
        }
        if(i == n) {
            return 0;
        }
        int ans=0;
        if(s[i]==t[j]){
            int include=solve(s,t,i+1,j+1);
            int exclude=solve(s,t,i+1,j);
            ans=include+exclude;
        } else{
            ans=solve(s,t,i+1,j);
        }
        return ans;
    }
    int solveUsingMem(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        int n=s.size();
        int m=t.size();
        if(j == m) {
            return 1;
        }
        if(i == n) {
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==t[j]){
            int include=solveUsingMem(s,t,i+1,j+1,dp);
            int exclude=solveUsingMem(s,t,i+1,j,dp);
            ans=include+exclude;
        } else{
            ans=solveUsingMem(s,t,i+1,j,dp);
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solveUsingMem(s,t,0,0,dp);
    }
};