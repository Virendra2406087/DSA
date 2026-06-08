class Solution {
public:
    // bool check(vector<int>& curr,vector<int>& prev){
    //     if(prev[0]<curr[0] && prev[1]<curr[1]){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }
    // int solve(vector<vector<int>>& envelopes,int currIndex,int prevIndex){
    //     int n=envelopes.size();
    //     int m=envelopes[0].size();
    //     if(currIndex == envelopes.size()){
    //         return 0;
    //     } 
    //     int include=0;
    //     if(prevIndex ==-1 || check(envelopes[currIndex],envelopes[prevIndex])){
    //         include = 1 + solve(envelopes, currIndex + 1, currIndex);
    //     }
    //     int exclude=0+solve(envelopes,currIndex+1,prevIndex);
    //     return max(include,exclude);
    // }
    // int solveUsingMem(vector<vector<int>>& cuboids,int currIndex,int prevIndex,vector<vector<int>>& dp){
    //     int n=cuboids.size();
    //     int m=cuboids[0].size();
    //     if(currIndex == cuboids.size()){
    //         return 0;
    //     } 
    //     if(dp[prevIndex+1][currIndex] != -1){
    //         return dp[prevIndex+1][currIndex];
    //     }
    //     int include=0;
    //     if(prevIndex ==-1 || check(cuboids[currIndex],cuboids[prevIndex])){
    //         include = 1 + solveUsingMem(cuboids, currIndex + 1, currIndex,dp);
    //     }
    //     int exclude=0+solveUsingMem(cuboids,currIndex+1,prevIndex,dp);
    //     dp[prevIndex+1][currIndex]= max(include,exclude);
    //     return dp[prevIndex+1][currIndex];
    // }
    // int solveUsingTab(vector<vector<int>>& cuboids){
    //     int n=cuboids.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //     for(int currInd=n-1;currInd>=0;currInd--){
    //         for(int prevInd=currInd-1;prevInd>=-1;prevInd--){
    //             int include=0;
    //             if(prevInd ==-1 || check(cuboids[currInd],cuboids[prevInd])){
    //                 include = cuboids[currInd][2] + dp[currInd + 1][currInd+1];
    //             }
    //             int exclude=0+dp[currInd+1][prevInd+1];
    //             dp[currInd][prevInd+1] = max(include, exclude);
    //         }
    //     }
    //     return dp[0][0];
    // }
    // int solveUsingTabSO(vector<vector<int>>& envelopes){
    //     int n=envelopes.size();
    //     vector<int>currRow(n+1,0);
    //     vector<int>nextRow(n+1,0);
    //     for(int currInd=n-1;currInd>=0;currInd--){
    //         for(int prevInd=currInd-1;prevInd>=-1;prevInd--){
    //             int include=0;
    //             if(prevInd ==-1 || check(envelopes[currInd],envelopes[prevInd])){
    //                 include = 1 + nextRow[currInd + 1];
    //             }
    //             int exclude=0+nextRow[prevInd+1];
    //             currRow[prevInd+1] = max(include, exclude);
    //         }
    //         nextRow=currRow;
    //     }
    //     return nextRow[0];
    // }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //  sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
        //     if(a[0] == b[0]) return a[1] > b[1];
        //     return a[0] < b[0];
        // });
        // return solveUsingTabSO(envelopes);

        sort(envelopes.begin(), envelopes.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] > b[1];
                return a[0] < b[0];
            });

        vector<int> lis;

        for (auto &env : envelopes) {
            int h = env[1];

            auto it = lower_bound(lis.begin(), lis.end(), h);

            if (it == lis.end())
                lis.push_back(h);
            else
                *it = h;
        }

        return lis.size();
    }
};