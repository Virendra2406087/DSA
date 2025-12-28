class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int mini=INT_MAX;
        int n=tasks.size();
        int m=tasks[0].size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                sum=sum+tasks[i][j];
            }
            mini=min(mini,sum);
        }
        return mini;
    }
};