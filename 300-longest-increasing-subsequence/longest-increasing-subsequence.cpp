class Solution {
public:
    int solve(vector<int>&nums,int curr,int prev){
        if(curr>=nums.size()){
            return 0;
        }
        int include=0;
        if(prev ==-1 || nums[curr]>nums[prev]){
           include=1+solve(nums,curr+1,curr);
        }
        int exclude=solve(nums,curr+1,prev);
        return max(include,exclude);
    }
    int solveUsingMem(vector<int>&nums,int curr,int prev,vector<vector<int>>&dp){
        if(curr>=nums.size()){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        int include=0;
        if(prev ==-1 || nums[curr]>nums[prev]){
           include=1+solveUsingMem(nums,curr+1,curr,dp);
        }
        int exclude=solveUsingMem(nums,curr+1,prev,dp);
        dp[curr][prev+1] = max(include,exclude);
        return dp[curr][prev+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solveUsingMem(nums,0,-1,dp);
        return ans;
    }
};