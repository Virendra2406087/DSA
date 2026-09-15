class Solution {
public:
    int solve(vector<int>& nums,int index){
        if(index >= nums.size()){
            return 0;
        }
        int include=nums[index]+solve(nums,index+2);
        int exclude=solve(nums,index+1);
        return max(include,exclude);
    }
    int solveUsingMem(vector<int>& nums,int index,vector<int>& dp){
        if(index >= nums.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int include=nums[index]+solveUsingMem(nums,index+2,dp);
        int exclude=solveUsingMem(nums,index+1,dp);
        dp[index]= max(include,exclude);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solveUsingMem(nums,0,dp);
    }
};