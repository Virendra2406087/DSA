class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });

        int result = 0;
        int maxRight = -1;

        for (int i = 0; i < intervals.size(); i++) {
            int r = intervals[i][1];

            if (r > maxRight) {
                result++;
                maxRight = r;
            }
        }

        return result;
    }
};