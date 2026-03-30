class Solution {
public:
    bool solve(vector<int>&nums,int n,int index){
        if(index>=n-1){
            return true;
        }
        for(int i=1;i<= nums[index];i++){
            bool ans=solve(nums,n,index+i);
            if(ans==true){
                return true;
            }
        }
        return false;
        
    }
    bool solveUsingMem(vector<int>&nums,int n,int index,vector<int>&dp){
        if(index>=n-1){
            return true;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        for(int i=1;i<= nums[index];i++){
            bool ans=solveUsingMem(nums,n,index+i,dp);
            if(ans==true){
                dp[index]= true;
                return dp[index];
            }
        }
        dp[index]= false;
        return dp[index];
        
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solveUsingMem(nums,n,0,dp);
    }
};