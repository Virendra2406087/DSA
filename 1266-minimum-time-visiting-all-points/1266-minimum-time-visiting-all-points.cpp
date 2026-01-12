class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int m=points.size();
        int steps=0;
        for(int i=0;i<m-1;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            int x2=points[i+1][0];
            int y2=points[i+1][1];
            int dx=abs(x1-x2);
            int dy=abs(y1-y2);
            steps=steps+(min(dx,dy)+abs(dx-dy));
        }
        return steps;
    }
};