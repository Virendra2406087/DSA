class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int s=0;
        int e=n-1;
        int ans=n;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==mid){
                s=mid+1;
            }else {
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
    }
};