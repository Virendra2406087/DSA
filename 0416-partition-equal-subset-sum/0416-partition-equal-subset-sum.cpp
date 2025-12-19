class Solution {
public:
    bool solveUsingRec(vector<int> & nums,int index,int target){
        int n=nums.size();
        if(index>=n){
          return 0;
        }
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        bool include=solveUsingRec(nums,index+1,target-nums[index]);
        bool exclude=solveUsingRec(nums,index+1,target);
        return (include || exclude);
    }
    bool solveUsingMem(vector<int> & nums,int index,int target,vector<vector<int>>& dp){
        int n=nums.size();
        if(index>=n){
          return 0;
        }
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(dp[index][target] !=-1){
            return dp[index][target];
        }
        bool include=solveUsingMem(nums,index+1,target-nums[index],dp);
        bool exclude=solveUsingMem(nums,index+1,target,dp);
        bool ans= (include || exclude);
        dp[index][target]=ans;
        return dp[index][target];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
       
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        if(sum %2 !=0){
            return false;
        }
        int target=sum/2;
        int index=0;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        bool ans=solveUsingMem(nums,index,target,dp);
        return ans;
    }
};