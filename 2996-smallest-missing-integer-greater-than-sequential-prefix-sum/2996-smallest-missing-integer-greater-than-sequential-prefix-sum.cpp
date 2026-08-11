class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int seqSum=nums[0];
        for(int j=1;j<nums.size();j++){
            if(nums[j]==nums[j-1]+1){
                seqSum+=nums[j];
            }else{
                break;
            }
        }
        while(st.count(seqSum)){
            seqSum++;
        }
        return seqSum;
    }
};