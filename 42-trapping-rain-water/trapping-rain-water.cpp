class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax=0;
        int rightMax=0;
        int left=0;
        int water=0;
        int right=height.size()-1;
        while(left<right){
            if(height[left]<height[right]){
                leftMax=max(leftMax,height[left]);
                water+=leftMax-height[left];
                left++;
            }
            else{
                rightMax=max(rightMax,height[right]);
                water+=rightMax-height[right];
                right--;
            }
        }
        return water;
    }
};