class Solution {
public:
    int distinctAverages(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = nums.size() - 1;
        
        unordered_set<int> st;
        
        while(i < j){
            st.insert(nums[i] + nums[j]);
            i++;
            j--;
        }
        
        return st.size();
    }
};