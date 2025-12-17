#include<vector>
#include <algorithm>
class Solution {
public:
    int solveUsingRec(vector<int>& nums,int curr,int prev){
        if(curr>=nums.size()){
            return 0;
        }
        int includeAns=0;
        if(prev ==-1 || nums[curr]>nums[prev]){
            includeAns=1+solveUsingRec(nums,curr+1,curr);
        }
        int excludeAns=0+solveUsingRec(nums,curr+1,prev);
        int finalAns=max(includeAns,excludeAns);
        return finalAns;
    }
    int solveUsingMem(vector<int>& nums,int curr,int prev,vector<vector<int>>&dp){
        if(curr>=nums.size()){
            return 0;
        }
        if(dp[curr][prev+1] !=-1){
           return dp[curr][prev+1];
        }
        int includeAns=0;
        if(prev ==-1 || nums[curr]>nums[prev]){
            includeAns=1+solveUsingMem(nums,curr+1,curr,dp);
        }
        int excludeAns=0+solveUsingMem(nums,curr+1,prev,dp);
        int finalAns=max(includeAns,excludeAns);
        dp[curr][prev+1]=finalAns;
        return dp[curr][prev+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int curr=0;
        int prev=-1;
        int ans=solveUsingMem(nums,curr,prev,dp);
        return ans;
    }
};