class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        vector<int>result;
        while(i<n){
        set<int>pref;
        set<int>suff;
        for(int j=0;j<=i;j++){
            pref.insert(nums[j]);
        }
        for(int j=i+1;j<n;j++){
            suff.insert(nums[j]);
        }
        int diff=pref.size()-suff.size();
            result.push_back(diff);
            i++;
            pref.clear();
            suff.clear();
        }
        return result;
    }
};