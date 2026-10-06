class Solution {
    int solve(int []nums,int i){
        if(i >= nums.length){
            return 0;
        }
        int include=nums[i] + solve(nums,i+2);
        int exclude=0+solve(nums,i+1);
        return Math.max(include,exclude);
    }
    int solveUsingMem(int []nums,int i,List<Integer>dp){
        if(i >= nums.length){
            return 0;
        }
        if(dp.get(i) != -1){
            return dp.get(i);
        }
        int include=nums[i] + solveUsingMem(nums,i+2,dp);
        int exclude=0+solveUsingMem(nums,i+1,dp);
        dp.set(i,Math.max(include,exclude));
        return dp.get(i);
    }
    public int rob(int[] nums) {
        List<Integer>dp=new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            dp.add(-1);
        }
        return solveUsingMem(nums,0,dp);
    }
}