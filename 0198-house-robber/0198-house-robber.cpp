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
    int solveUsingTab(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int temp=0;
            if(i+2<=n){
                temp=dp[i+2];
            }
            int include=temp+nums[i];
            int exclude=dp[i+1];
            dp[i]= max(include,exclude);
        }
        return dp[0];
    }
    int solveUsingTabSO(vector<int>& nums) {
        int n=nums.size();
        int next1=0;
        int next2=0;
        int curr;
        for(int i=n-1;i>=0;i--){
            int temp=0;
            if(i+2<=n){
                temp=next2;
            }
            int include=temp+nums[i];
            int exclude=next1;
            curr= max(include,exclude);
            next2=next1;
            next1=curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solveUsingTabSO(nums);
    }
};