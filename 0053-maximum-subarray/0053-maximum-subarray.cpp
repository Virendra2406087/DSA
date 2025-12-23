class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currSum=0;
        int maxi=INT_MIN;
        for(int x:nums){
            currSum=max(x,currSum+x);
            maxi=max(maxi,currSum);
        }
    return maxi;
    }
};