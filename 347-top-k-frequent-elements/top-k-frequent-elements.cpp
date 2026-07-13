class Solution {
public:
   struct lambda{
        bool operator()(pair<int,int>&p1,pair<int,int> &p2){
            return p1.second < p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),lambda());
        vector<int>ans;
        int m=v.size();
        for(int i=m-1;i>=m-k;i--){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};