class Solution {
public:
    vector<int>dp;
    bool fnc(int n,vector<int>& dp){
        if(n==0){
            return false;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        for(int i=1;i*i<=n;i++){
            if(fnc(n-i*i,dp)==false){
                return dp[n]=1;
            }
        }
        return dp[n]=0;

    }
    bool winnerSquareGame(int n) {
        dp.resize(n+1,-1);
        return fnc(n,dp);
    }
};