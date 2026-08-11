class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>st;
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
            if(abs(j-i)>k){
                st.erase(nums[i]);
                i++;
            }
            if(st.find(nums[j]) != st.end()){
                return true;
            }
            st.insert(nums[j]);
            j++;
        }
        return false;
    }
};