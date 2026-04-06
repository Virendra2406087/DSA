class Solution {
public:
    int solve(string& a,string &b,int i,int j){
        if(i==a.length()){
            return b.length()-j;
        }
        if(j==b.length()){
            return a.length()-i;
        }
        int ans=0;
        if(a[i]==b[j]){
            ans=solve(a,b,i+1,j+1);
        }else{
            int insert=1+solve(a,b,i,j+1);
            int deleted=1+solve(a,b,i+1,j);
            int replace=1+solve(a,b,i+1,j+1);
            ans=min(insert,min(deleted,replace));
        }
        return ans;
    }
    int solveUsingMem(string& a,string &b,int i,int j,vector<vector<int>>&dp){
        if(i==a.length()){
            return b.length()-j;
        }
        if(j==b.length()){
            return a.length()-i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans=0;
        if(a[i]==b[j]){
            ans=solveUsingMem(a,b,i+1,j+1,dp);
        }else{
            int insert=1+solveUsingMem(a,b,i,j+1,dp);
            int deleted=1+solveUsingMem(a,b,i+1,j,dp);
            int replace=1+solveUsingMem(a,b,i+1,j+1,dp);
            ans=min(insert,min(deleted,replace));
        }
        dp[i][j]= ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solveUsingMem(word1,word2,0,0,dp);
    }
};