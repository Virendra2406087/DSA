class Solution {
public:
    int solve(vector<int>&nums){
        int maxReach=0;
        int end=0;
        int jumps=0;
        for(int i=0;i<nums.size()-1;i++){
            maxReach=max(maxReach,i+nums[i]);
            if(i==end){
                jumps++;
                end=maxReach;
            }
        }
        return jumps;

    }
    int jump(vector<int>& nums) {
        return solve(nums);
    }
};