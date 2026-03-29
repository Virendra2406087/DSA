class Solution {
public:
    bool solve(vector<int>&nums,int index,int target){
        int n=nums.size();
        if(index>=n){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        bool include=solve(nums,index+1,target-nums[index]);
        bool exclude=solve(nums,index+1,target);
        return (include||exclude);

    }
    bool solveUsingMem(vector<int>&nums,int index,int target,vector<vector<int>>&dp){
        int n=nums.size();
        if(index>=n){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        if(dp[target][index] != -1){
            return dp[target][index];
        }
        bool include=solveUsingMem(nums,index+1,target-nums[index],dp);
        bool exclude=solveUsingMem(nums,index+1,target,dp);
        dp[target][index]= (include||exclude);
        return dp[target][index];

    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        if(sum & 1){
            return 0;
        }
        int target=sum/2;
        int n=nums.size();
        vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
        bool ans=solveUsingMem(nums,0,target,dp);
        return ans;
    }
};