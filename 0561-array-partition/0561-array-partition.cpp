class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i=i+2){
            ans=ans+min(nums[i],nums[i+1]);
        }

        return ans;
    }
};