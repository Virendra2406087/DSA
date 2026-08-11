class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        int i=0;
        while(i<nums.size()){
            if(st.find(nums[i]) != st.end()){
                return true;
            }
            st.insert(nums[i]);
            i++;
        }
        return false;
    }
};