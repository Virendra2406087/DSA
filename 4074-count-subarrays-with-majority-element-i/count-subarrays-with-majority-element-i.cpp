class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count=0;
        for(int j=0;j<nums.size();j++){
            int cnt=0;
            for(int i=j;i<nums.size();i++){
                if(nums[i]==target){
                    cnt++;
                }
                if(cnt>(i-j+1)/2){
                    count++;
                }
            }
        }
        return count;
    }
};