class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        if (intervals.empty()){
            return 0;    
        } 
        sort(intervals.begin(), intervals.end());
        long long totalTime = 0;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            } else {
                totalTime += 1LL * (end - start + 1);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        totalTime += 1LL * (end - start + 1);
        long long bulbs = (brightness + 2LL) / 3;
        bulbs = min(bulbs, 1LL * n);

        return totalTime * bulbs;
    }
};