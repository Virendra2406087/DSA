class Solution {
public:
    int solveUsingRec(vector<int>& nums1,vector<int>& nums2,int i,int j){
        if(i>=nums1.size() || j>=nums2.size()){
            return -1e5;
        }
        int val=nums1[i]*nums2[j];
        int take_i_j=(nums1[i]*nums2[j])+solveUsingRec(nums1,nums2,i+1,j+1);
        int take_i=solveUsingRec(nums1,nums2,i+1,j);
        int take_j=solveUsingRec(nums1,nums2,i,j+1);
        return max({val,take_i_j,take_i,take_j});
    }
    int solveUsingMem(vector<int>& nums1,vector<int>& nums2,int i,int j,vector<vector<int>>& dp){
        int n=nums1.size();
        int m=nums2.size();
        if(i>=n || j>=m){
            return -1e7;
        }
        if(dp[i][j] !=INT_MIN){
            return dp[i][j];
        }
        int val=nums1[i]*nums2[j];
        int take_i_j=(nums1[i]*nums2[j])+solveUsingMem(nums1,nums2,i+1,j+1,dp);
        int take_i=solveUsingMem(nums1,nums2,i+1,j,dp);
        int take_j=solveUsingMem(nums1,nums2,i,j+1,dp);
        dp[i][j]= max({val,take_i_j,take_i,take_j});
        return dp[i][j];
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MIN));
        
        int ans=solveUsingMem(nums1,nums2,0,0,dp);
        return ans;
    }
};