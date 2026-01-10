class Solution {
public:
    int solve(string s1 ,string s2,int i,int j){
        int m=s1.size();
        int n=s2.size();
        if(i>=m && j>=n){
            return 0;
        }
        if(i>=m){
            return int(s2[j])+solve(s1,s2,i,j+1);
        }
        if(j>=n){
            return int(s1[i])+solve(s1,s2,i+1,j);
        }
        if(s1[i]==s2[j]){
            return solve(s1,s2,i+1,j+1);
        }
        int delete_s1_i=int(s1[i])+solve(s1,s2,i+1,j);
        int delete_s2_j=int(s2[j])+solve(s1,s2,i,j+1);
        return min(delete_s1_i,delete_s2_j);
    }
    int solveMem(string &s1 ,string &s2,int i,int j,vector<vector<int>> &dp){
        int m=s1.size();
        int n=s2.size();
        if(i>=m && j>=n){
            return 0;
        }
        if(dp[i][j] !=-1){
            return dp[i][j];
        }
        if(i>=m){
            return int(s2[j])+solveMem(s1,s2,i,j+1,dp);
        }
        if(j>=n){
            return int(s1[i])+solveMem(s1,s2,i+1,j,dp);
        }
        if(s1[i]==s2[j]){
            return solveMem(s1,s2,i+1,j+1,dp);
        }
        int delete_s1_i=int(s1[i])+solveMem(s1,s2,i+1,j,dp);
        int delete_s2_j=int(s2[j])+solveMem(s1,s2,i,j+1,dp);
        dp[i][j]= min(delete_s1_i,delete_s2_j);
        return dp[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans=solveMem(s1,s2,0,0,dp);
        return ans;
    }
};