class Solution {
public:
    int solve(string a,string b,int i,int j){
        if(i >= a.length() || j >= b.length()){
            return 0;
        }
        int ans=0;
        if(a[i]==b[j]){
            ans=1+solve(a,b,i+1,j+1);
        }else{
            ans=0+max(solve(a,b,i+1,j),solve(a,b,i,j+1));
        }
        return ans;
    }
    int solveUsingMem(string &a,string& b,int i,int j,vector<vector<int>>&dp){
        if(i >= a.length() || j >= b.length()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans=0;
        if(a[i]==b[j]){
            ans=1+solveUsingMem(a,b,i+1,j+1,dp);
        }else{
            ans=0+max(solveUsingMem(a,b,i+1,j,dp),solveUsingMem(a,b,i,j+1,dp));
        }
        dp[i][j]= ans;
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string b=s;
        reverse(b.begin(),b.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveUsingMem(s,b,0,0,dp);
    }
};