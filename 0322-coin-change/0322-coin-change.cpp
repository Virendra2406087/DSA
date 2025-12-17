class Solution {
public:
    int solveUsingRec(vector<int>&coins,int amount){
        if(amount==0){
            return 0;
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){
              int recursionAns= solveUsingRec(coins,amount-coins[i]);
              if(recursionAns !=INT_MAX){
                mini=min(1+recursionAns,mini);
              }else{
                return -1;
              }
            }
        }
        return mini;
    } 
    int solveUsingMem(vector<int>&coins,int amount,vector<int>&dp){
        if(amount==0){
            return 0;
        }
        if(dp[amount] !=-1){
            return dp[amount];
        }

        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){
              int recursionAns= solveUsingMem(coins,amount-coins[i],dp);
              if(recursionAns !=INT_MAX){
                mini=min(1+recursionAns,mini);
              }
            }
        }
        dp[amount]=mini;
        return dp[amount];
    }
    int solveUsingTab(vector<int>& coins, int amount){
        vector<int>dp(amount+1,-1);
        dp[0]=0;
        for(int value=1;value<=amount;value++){
            int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=value){
              int recursionAns= dp[value-coins[i]];
              if(recursionAns !=INT_MAX){
                mini=min(1+recursionAns,mini);
              }
            }
           dp[value]=mini;
        }
     }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,-1);
        int ans=solveUsingTab(coins,amount);
        if(ans==INT_MAX){
            return -1;
        }else{
        return ans;
        }
    }
};