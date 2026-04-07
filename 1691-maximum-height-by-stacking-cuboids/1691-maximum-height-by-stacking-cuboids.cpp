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
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &c : cuboids) {
            sort(c.begin(), c.end());
        }
        sort(cuboids.begin(), cuboids.end());
        return solve(cuboids,0,-1);
    }
};