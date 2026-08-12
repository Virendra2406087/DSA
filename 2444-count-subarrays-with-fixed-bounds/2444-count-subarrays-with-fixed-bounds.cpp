class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minPosition=-1;
        int maxPosition=-1;
        int culPosition=-1;
        for(int i = 0;i< nums.size() ;i++){
            if(nums[i]<minK || nums[i]>maxK){
                culPosition=i;
            }
            if(nums[i]==minK){
                minPosition=i;
            }
            if(nums[i]==maxK){
                maxPosition=i;
            }
            long long smaller=min(minPosition,maxPosition);
            long long temp=smaller-culPosition;
            ans+=(temp<=0)? 0:temp;
        }
        return ans;
    }
};