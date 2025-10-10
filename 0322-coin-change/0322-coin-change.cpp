class Solution {
public:
    int solveUsingRec(vector<int>& coins,int amount){
        // base case
        if(amount==0){
            return 0;
        }

        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){
                int ans=solveUsingRec(coins,amount-coins[i]);
            if(ans !=INT_MAX){
                mini=min(mini,1+ans);
            }
          } 
        }
        return mini;
    }
    int solveUsingMem(vector<int>& coins, int amount,vector<int> & dp){
        // base case
        if(amount==0){
            return 0;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }

        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){
                int ans=solveUsingMem(coins,amount-coins[i],dp);
            if(ans !=INT_MAX){
                mini=min(mini,1+ans);
            }
          } 
        }
                dp[amount]=mini;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=amount;
        vector<int>dp(n+1,-1);
        int ans=solveUsingMem(coins,amount,dp);
        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};