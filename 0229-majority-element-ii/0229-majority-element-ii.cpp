class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        int n=nums.size();
        vector<int>ans;
        for(int i:nums){
            freq[i]++;
        }
        for(auto &j:freq){
            if(j.second>n/3){
                ans.push_back(j.first);
            }
        }
        return ans;
    }
};