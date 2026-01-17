class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        for(int i:nums){
         freq[i]++;
        }
        for(auto &j:freq){
            if(j.second>n/2){
                return j.first;
            }
        }
        return -1;
    }
};