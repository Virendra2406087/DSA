class Solution {
public:
    int solve(int l,int r,vector<int>& cumSum) {
        if(l==r){
            return 0;
        }
        int score=0;
        for(int mid=l;mid<=r-1;mid++){
            int leftSum=cumSum[mid]-(l-1>=0 ? cumSum[l-1] : 0);
            int rightSum=cumSum[r]-cumSum[mid];
            if(leftSum<rightSum){
                score=max(score,leftSum+solve(l,mid,cumSum));
            } else if(leftSum > rightSum) {
                score=max(score,rightSum+solve(mid+1,r,cumSum));
            } else {
                score=max({score,leftSum+solve(l,mid,cumSum),rightSum+solve(mid+1,r,cumSum)});
            }
        }
        return score;

    }
    int solveUsingMem(int l,int r,vector<int>& cumSum,vector<vector<int>>& dp) {
        if(l==r){
            return 0;
        }
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        int score=0;
        for(int mid=l;mid<=r-1;mid++){
            int leftSum=cumSum[mid]-(l-1>=0 ? cumSum[l-1] : 0);
            int rightSum=cumSum[r]-cumSum[mid];
            if(leftSum<rightSum){
                score=max(score,leftSum+solveUsingMem(l,mid,cumSum,dp));
            } else if(leftSum > rightSum) {
                score=max(score,rightSum+solveUsingMem(mid+1,r,cumSum,dp));
            } else {
                score=max({score,leftSum+solveUsingMem(l,mid,cumSum,dp),rightSum+solveUsingMem(mid+1,r,cumSum,dp)});
            }
        }
        dp[l][r] =score;
        return dp[l][r];

    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>cumSum(n,0);
        cumSum[0]=stoneValue[0];
        for(int i=1;i<n;i++){
            cumSum[i]=cumSum[i-1]+stoneValue[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveUsingMem(0,n-1,cumSum,dp);
    }
};