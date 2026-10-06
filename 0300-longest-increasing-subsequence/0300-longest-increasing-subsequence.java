class Solution {
    int solve(int[] nums,int curr,int prev){
        if(curr >= nums.length){
            return 0;
        }
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1+solve(nums,curr+1,curr);
        }
        int exclude=solve(nums,curr+1,prev);
        return Math.max(include,exclude);
    }
    int solveUsingMem(int[] nums,int curr,int prev,List<List<Integer>> dp){
        if(curr >= nums.length){
            return 0;
        }
        if(dp.get(prev+1).get(curr) != -1){
            return dp.get(prev+1).get(curr);
        }
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1+solveUsingMem(nums,curr+1,curr,dp);
        }
        int exclude=solveUsingMem(nums,curr+1,prev,dp);
        dp.get(prev+1).set(curr,Math.max(include,exclude));
        return dp.get(prev+1).get(curr) ;
    }
    public int lengthOfLIS(int[] nums) {
        int n=nums.length;
        List<List<Integer>> dp= new ArrayList<>();
        for(int i=0;i<=n;i++){
            List<Integer> temp= new ArrayList<>();
            for(int j=0;j<=n;j++){
               temp.add(-1);
            }
            dp.add(temp);
        }
        return solveUsingMem(nums,0,-1,dp);
    }
}