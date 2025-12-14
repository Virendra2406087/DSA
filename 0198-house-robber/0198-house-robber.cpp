class Solution {
public:
    int solveUsingRec(vector<int>&nums,int index){
        if(index>=nums.size()){
            return 0;
        }
        int include=nums[index]+solveUsingRec(nums,index+2);
        int exclude=0+solveUsingRec(nums,index+1);
        int ans=max(include,exclude);
        return ans;
    }
    int solveUsingMem(vector<int>&nums,int index,vector<int>&dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index] !=-1){
            return dp[index];
        }
        int include=nums[index]+solveUsingMem(nums,index+2,dp);
        int exclude=0+solveUsingMem(nums,index+1,dp);
        int ans=max(include,exclude);
        dp[index]=ans;
        return dp[index];
    }
   
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int ans=solveUsingMem(nums,0,dp);
        return ans;
    }
};