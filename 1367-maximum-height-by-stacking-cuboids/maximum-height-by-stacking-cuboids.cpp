class Solution {
public:
    bool check(vector<int>& curr,vector<int>& prev){
        if(prev[0]<=curr[0] && prev[1]<=curr[1] && prev[2]<=curr[2]){
            return true;
        }
        else{
            return false;
        }
    }
    int solve(vector<vector<int>>& cuboids,int currIndex,int prevIndex){
        int n=cuboids.size();
        int m=cuboids[0].size();
        if(currIndex == cuboids.size()){
            return 0;
        } 
        int include=0;
        if(prevIndex ==-1 || check(cuboids[currIndex],cuboids[prevIndex])){
            include = cuboids[currIndex][2] + solve(cuboids, currIndex + 1, currIndex);
        }
        int exclude=0+solve(cuboids,currIndex+1,prevIndex);
        return max(include,exclude);
    }
    int solveUsingMem(vector<vector<int>>& cuboids,int currIndex,int prevIndex,vector<vector<int>>& dp){
        int n=cuboids.size();
        int m=cuboids[0].size();
        if(currIndex == cuboids.size()){
            return 0;
        } 
        if(dp[prevIndex+1][currIndex] != -1){
            return dp[prevIndex+1][currIndex];
        }
        int include=0;
        if(prevIndex ==-1 || check(cuboids[currIndex],cuboids[prevIndex])){
            include = cuboids[currIndex][2] + solveUsingMem(cuboids, currIndex + 1, currIndex,dp);
        }
        int exclude=0+solveUsingMem(cuboids,currIndex+1,prevIndex,dp);
        dp[prevIndex+1][currIndex]= max(include,exclude);
        return dp[prevIndex+1][currIndex];
    }
    int solveUsingTab(vector<vector<int>>& cuboids){
        int n=cuboids.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int currInd=n-1;currInd>=0;currInd--){
            for(int prevInd=currInd-1;prevInd>=-1;prevInd--){
                int include=0;
                if(prevInd ==-1 || check(cuboids[currInd],cuboids[prevInd])){
                    include = cuboids[currInd][2] + dp[currInd + 1][currInd+1];
                }
                int exclude=0+dp[currInd+1][prevInd+1];
                dp[currInd][prevInd+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(auto &c : cuboids) {
            sort(c.begin(), c.end());
        }
        sort(cuboids.begin(), cuboids.end());
        return solveUsingTab(cuboids);
    }
};