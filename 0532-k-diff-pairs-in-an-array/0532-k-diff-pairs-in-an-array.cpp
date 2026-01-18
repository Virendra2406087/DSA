class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0){
            return 0;
        }
        unordered_map<int ,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int count1=0;
        if(k==0){
            for(auto x:mp){
                if(x.second>1){
                    count1++;
                }
            }
            return count1;
        }
        for(auto x:mp){
            if(mp.count(x.first-k)){
                count1++;
            }
        }
        return count1;

    }
};