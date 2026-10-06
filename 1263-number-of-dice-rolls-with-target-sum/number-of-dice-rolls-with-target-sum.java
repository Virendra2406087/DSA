class Solution {
    long mod = 1000000007L;

    int solve(int n,int k,int target){
        if(n < 0 || target < 0){
            return 0;
        }

        if(n == 0 && target == 0){
            return 1;
        }

        if(n == 0 && target != 0){
            return 0;
        }

        if(n != 0 && target == 0){
            return 0;
        }

        int ans = 0;

        for(int val = 1; val <= k; val++){
            ans = ans + solve(n-1,k,target-val);
        }

        return ans;
    }

    long solveUsingMem(int n,int k,int target,List<List<Long>> dp){

        if(n < 0 || target < 0){
            return 0;
        }

        if(n == 0 && target == 0){
            return 1;
        }

        if(n == 0 && target != 0){
            return 0;
        }

        if(n != 0 && target == 0){
            return 0;
        }

        if(dp.get(n).get(target) != -1){
            return dp.get(n).get(target);
        }

        long ans = 0;

        for(int val = 1; val <= k; val++){
            ans = (ans + solveUsingMem(n-1,k,target-val,dp)) % mod;
        }

        dp.get(n).set(target,ans);

        return dp.get(n).get(target);
    }

    public int numRollsToTarget(int n, int k, int target) {

        List<List<Long>> dp = new ArrayList<>();

        for(int i = 0; i <= n; i++){

            List<Long> temp = new ArrayList<>();

            for(int j = 0; j <= target; j++){
                temp.add(-1L);
            }

            dp.add(temp);
        }

        return (int)solveUsingMem(n,k,target,dp);
    }
}