#include<vector>
#include<set>
class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());
        sort(v.begin(),v.end());
        int n=v.size();
        k=min(k,n);
        vector<int>ans;
        for(int i=n-1;i>=n-k;i--){
            ans.push_back(v[i]);
        }
        return ans;
    }
};