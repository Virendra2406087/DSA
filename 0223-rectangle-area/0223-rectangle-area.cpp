class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int width1=abs(ax1-ax2);
        int height1=abs(ay1-ay2);
        int width2=abs(bx1-bx2);
        int height2=abs(by1-by2);
        int totalArea=height1*width1+height2*width2;
        
        int overlapWidth = min(ax2, bx2) - max(ax1, bx1);
        int overlapHeight = min(ay2, by2) - max(ay1, by1);
        if(overlapHeight > 0 && overlapWidth > 0){
            return totalArea-(overlapHeight*overlapWidth);
        }
        return totalArea;
    }
};