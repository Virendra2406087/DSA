class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int px = max(x1,min(xCenter,x2));
        int py = max(y1,min(yCenter,y2));
        int dx=xCenter - px;
        int dy=yCenter - py;
        return dx*dx+dy*dy <= radius*radius;
    }
};