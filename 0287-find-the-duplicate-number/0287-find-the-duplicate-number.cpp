class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n+1,0);
        for(int i=0;i<n;i++){
              if(!ans[nums[i]]){
                ans[nums[i]]=1;
              }else{
                return nums[i];
              }
        }
        return -1;
    }
};