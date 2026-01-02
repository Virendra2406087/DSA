class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            int count=0;
           for(int j=i;j<n;j++){
               if(nums[i]==nums[j]){
                count++;
                 
                  if(count>1){
                    ans=nums[i];
                  }
               }
           }
        }
        return ans;
    }
};