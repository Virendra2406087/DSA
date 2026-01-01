class Solution {
public:
    int solve(vector<int>& prices,int i,bool buy){
        if(i>=prices.size()){
            return 0;
        }
        int profit=0;
        if(buy){
            int buyProfit=-prices[i]+solve(prices,i+1,0);
            int skipProfit=0+solve(prices,i+1,1);
            profit=max(buyProfit,skipProfit);
        }else{
            int sellProfit=prices[i]+solve(prices,i+1,1);
            int skipProfit=solve(prices,i+1,0);
            profit=max(sellProfit,skipProfit);
        }
        return profit;
    }
    int solveMem(vector<int>& prices,int i,bool buy,vector<vector<int>>& dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy] !=-1){
            return dp[i][buy];
        }
        int profit=0;
        if(buy){
            int buyProfit=-prices[i]+solveMem(prices,i+1,0,dp);
            int skipProfit=0+solveMem(prices,i+1,1,dp);
            profit=max(buyProfit,skipProfit);
        }else{
            int sellProfit=prices[i]+solveMem(prices,i+1,1,dp);
            int skipProfit=solveMem(prices,i+1,0,dp);
            profit=max(sellProfit,skipProfit);
        }
        dp[i][buy]= profit;
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solveMem(prices,0,true,dp);
        
    }
};