class Solution {
public:
    int solve(vector<int>& nums,int i,int end){
        int n=nums.size();
      if(i>end){
        return 0;
      }
      int includeSum = nums[i] + solve(nums, i+2,end); 
      int excludeSum = solve(nums, i+1,end);
      return max(includeSum, excludeSum);
    }
    int solveUsingMem(vector<int>& nums, int i, int end, vector<int>& dp){
        if(i > end) return 0;
        if(dp[i] != -1) return dp[i];

        int includeSum = nums[i] + solveUsingMem(nums, i+2, end, dp);
        int excludeSum = solveUsingMem(nums, i+1, end, dp);

        return dp[i] = max(includeSum, excludeSum);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int>dp1(n, -1);
        vector<int>dp2(n, -1);
        int case1 = solveUsingMem(nums, 0, n - 2, dp1);
        int case2 = solveUsingMem(nums, 1, n - 1, dp2);

        return max(case1, case2);
    }
};