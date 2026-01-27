class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int count=1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
            if(count>2){
                return false;
            }
        }
        return true;
        
    }
};