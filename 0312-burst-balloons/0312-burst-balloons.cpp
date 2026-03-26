class Solution {
public:
    int solveUsingRec(vector<int>&nums,int i,int j){
        if(i>j){
            return 0;
        }
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
        int ans=solveUsingRec(nums,i,k-1)+solveUsingRec(nums,k+1,j)+nums[i-1]*nums[k]*nums[j+1];
        maxi=max(maxi,ans);

        }
        return maxi;
    }
    int solveUsingMem(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
        int ans=solveUsingMem(nums,i,k-1,dp)+solveUsingMem(nums,k+1,j,dp)+nums[i-1]*nums[k]*nums[j+1];
        maxi=max(maxi,ans);

        }
        dp[i][j]= maxi;
        return dp[i][j];
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        // 2-D dp
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solveUsingMem(nums,1,n,dp);
        return ans;
    }
};