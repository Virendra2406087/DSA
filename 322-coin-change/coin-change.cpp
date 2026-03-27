class Solution {
public:
     int solve(vector<int>& coins,int amount){
        if(amount==0){
            return 0;
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){
                int recursionAns=solve(coins,amount-coins[i]);
                if(recursionAns != INT_MAX){
                    mini=min(mini,1+recursionAns);
                }
            }
        }
        return mini;
     }
     int solveUsingMem(vector<int>& coins,int amount,vector<int>&dp){
        if(amount==0){
            return 0;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){
                int recursionAns=solveUsingMem(coins,amount-coins[i],dp);
                if(recursionAns != INT_MAX){
                    mini=min(mini,1+recursionAns);
                }
            }
        }
        dp[amount]= mini;
        return dp[amount];
     }
    int solveUsingTab(vector<int>&coins,int amount){
        int n=amount;
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int value=1;value<=amount;value++){
           int mini=INT_MAX;
           for(int i=0;i<coins.size();i++){
                if(coins[i]<=value){
                    int recursionAns=dp[value-coins[i]];
                    if(recursionAns != INT_MAX){
                        mini=min(mini,1+recursionAns);
                }
            }
        }
        dp[value]=mini; 
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans=solveUsingTab(coins,amount);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};