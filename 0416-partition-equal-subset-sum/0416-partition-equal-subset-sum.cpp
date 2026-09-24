class Solution {
public:
    bool solve(vector<int>& nums,int index, int target) {
        int n=nums.size();
        if(index >= n) {
            return false;
        }
        if(target == 0) {
            return true;
        }
        if(target < 0) {
            return false;
        }
        bool include = solve(nums,index+1,target-nums[index]);
        bool exclude = solve(nums,index+1,target);
        return include||exclude;
    }
    bool solveUsingMem(vector<int>& nums,int index, int target,vector<vector<int>>& dp) {
        int n=nums.size();
        if(index >= n) {
            return false;
        }
        if(target == 0) {
            return true;
        }
        if(target < 0) {
            return false;
        }
        if(dp[target][index] != -1) {
            return dp[target][index];
        }
        bool include = solveUsingMem(nums,index+1,target-nums[index],dp);
        bool exclude = solveUsingMem(nums,index+1,target,dp);
        dp[target][index] = include||exclude;
        return dp[target][index];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum & 1) {
            return false;
        }
        int target = sum/2;
        vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
        bool ans = solveUsingMem(nums,0,target,dp);
        return ans;
    }
};