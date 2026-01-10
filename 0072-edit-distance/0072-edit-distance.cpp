class Solution {
public:
    int solve(string &s1,string &s2,int i,int j){
        int m=s1.length();
        int n=s2.length();
        if(i==m){
            return n-j;
        }
        if(j==n){
            return m-i;
        }
        if(s1[i]==s2[j]){
            return solve(s1,s2,i+1,j+1);
        }
        
        int insert=1+solve(s1,s2,i,j+1);
        int deleted=1+solve(s1,s2,i+1,j);
        int replace=1+solve(s1,s2,i+1,j+1);

        return min({insert,deleted,replace});
    }
    int solveMem(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
        int m=s1.length();
        int n=s2.length();
        if(i==m){
            return n-j;
        }
        if(j==n){
            return m-i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return solveMem(s1,s2,i+1,j+1,dp);
        }
        
        int insert=1+solveMem(s1,s2,i,j+1,dp);
        int deleted=1+solveMem(s1,s2,i+1,j,dp);
        int replace=1+solveMem(s1,s2,i+1,j+1,dp);

        dp[i][j] = min({insert,deleted,replace});
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans=solveMem(word1,word2,0,0,dp);
        return ans;
    }
};