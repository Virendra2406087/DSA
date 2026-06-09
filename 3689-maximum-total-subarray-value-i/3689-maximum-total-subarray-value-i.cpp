class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(auto i:nums){
            maxi=max(maxi,i);
        }
        for(auto i:nums){
            mini=min(mini,i);
        }
        return 1LL*(maxi-mini)*k;
    }
};