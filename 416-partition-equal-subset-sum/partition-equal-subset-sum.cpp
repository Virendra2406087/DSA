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
    bool solveUsingTab(vector<int>&nums,int target){
        int n=nums.size();
        vector<vector<int>>dp(target+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i]=1;
        }
        for(int t=1;t<=target;t++){
            for(int i=n-1;i>=0;i--){
                bool include=0;
                if(t-nums[i]>=0){
                    include=dp[t-nums[i]][i+1];
                }
                bool exclude=dp[t][i+1];
                dp[t][i]= (include || exclude);
            }
        }
       return dp[target][0];
    }
    bool solveUsingTabSO(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> dp(target+1, 0);

    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int t = target; t >= nums[i]; t--) {
            dp[t] = dp[t] || dp[t - nums[i]];
        }
    }

    return dp[target];
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
        bool ans=solveUsingTabSO(nums,target);
        return ans;
    }
};