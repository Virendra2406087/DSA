class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }

        vector<pair<int,int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });
        int n = v.size();
        for (int i = n - 1; i >= n - k; i--) {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};