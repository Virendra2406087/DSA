class Solution {
    int solve(int[] coins,int amount){
        if(amount == 0){
            return 0;
        }
        int mini=Integer.MAX_VALUE;
        for(int i=0;i<coins.length;i++){
            if(coins[i] <= amount){
                int recAns=solve(coins,amount-coins[i]);
                if(recAns != Integer.MAX_VALUE){
                    mini=Math.min(mini,1+recAns);
                }
            }
        }
        return mini;
    }
    int solveUsingMem(int[] coins,int amount,List<Integer> dp){
        if(amount == 0){
            return 0;
        }
        if(dp.get(amount) != -1){
            return dp.get(amount);
        }
        int mini=Integer.MAX_VALUE;
        for(int i=0;i<coins.length;i++){
            if(coins[i] <= amount){
                int recAns=solveUsingMem(coins,amount-coins[i],dp);
                if(recAns != Integer.MAX_VALUE){
                    mini=Math.min(mini,1+recAns);
                }
            }
        }
        dp.set(amount,mini);
        return dp.get(amount);
    }
    public int coinChange(int[] coins, int amount) {
        List<Integer> dp = new ArrayList<>();
        for(int i=0;i<=amount;i++){
            dp.add(-1);
        }
        int ans= solveUsingMem(coins,amount,dp);
        if(ans == Integer.MAX_VALUE){
            return -1;
        }
        return ans;
    }
}