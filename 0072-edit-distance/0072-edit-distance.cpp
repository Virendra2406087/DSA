class Solution {
public:
    int solve(string &word1, string &word2, int i, int j) {
        if(i == word1.size()) {
            return word2.size()-j;
        }
        if(j == word2.size()) {
            return word1.size()-i;
        }
        int ans = 0;
        if(word1[i] == word2[j]) {
            ans = solve(word1, word2, i+1, j+1);
        } else {
            int insert =1 + solve(word1, word2, i,j+1);
            int deleted =1 + solve(word1, word2, i+1,j);
            int replace =1 + solve(word1, word2, i+1,j+1);
            ans = min(insert, min(deleted, replace));
        }
        return ans;
    }
    int solveUsingMem(string &word1, string &word2, int i, int j,vector<vector<int>>& dp) {
        if(i == word1.size()) {
            return word2.size()-j;
        }
        if(j == word2.size()) {
            return word1.size()-i;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if(word1[i] == word2[j]) {
            ans = solveUsingMem(word1, word2, i+1, j+1,dp);
        } else {
            int insert =1 + solveUsingMem(word1, word2, i,j+1,dp);
            int deleted =1 + solveUsingMem(word1, word2, i+1,j,dp);
            int replace =1 + solveUsingMem(word1, word2, i+1,j+1,dp);
            ans = min(insert, min(deleted, replace));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size()-1;
        int m = word2.size()-1;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solveUsingMem(word1, word2, 0, 0,dp);
    }
};