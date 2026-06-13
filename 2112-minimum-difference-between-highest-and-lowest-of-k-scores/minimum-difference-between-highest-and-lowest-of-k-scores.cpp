class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int minDiff=INT_MAX;
        int i=0;
        int j=k-1;
        while(j<n){
            int minE=nums[i];
            int maxE=nums[j];
            minDiff=min(minDiff,maxE-minE);
            i++;
            j++;
        }
        return minDiff;
    }
};