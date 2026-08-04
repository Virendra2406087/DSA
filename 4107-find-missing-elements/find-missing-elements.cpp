class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int start=nums[0];
        int i=1;
        while(i<nums.size()){
            if(nums[i]==start+1){
                start=nums[i];
                i++;
            }else{
                ans.push_back(start+1);
                start=start+1;
            }
        }
        return ans;
    }
};