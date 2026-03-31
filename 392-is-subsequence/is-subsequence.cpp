class Solution {
public:
    bool solve(string s,string t,int i,int j){
        if(i>=s.length()){
            return true;
        }
        if(j>=t.length()){
            return false;
        }
        if(s[i]==t[j]){
            return solve(s,t,i+1,j+1);
        }else{
            return solve(s,t,i,j+1);
        }
    }
    bool solveUsingMem(string s,string t,int i,int j,vector<vector<int>>&dp){
        if(i>=s.length()){
            return true;
        }
        if(j>=t.length()){
            return false;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
          return  dp[i][j]= solveUsingMem(s,t,i+1,j+1,dp);
        }else{
           return dp[i][j]= solveUsingMem(s,t,i,j+1,dp);
        }
    }
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solveUsingMem(s,t,0,0,dp);
    }
};