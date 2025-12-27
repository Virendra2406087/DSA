class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int j=1;
        while(s.count(j)){
            j++;
        }
        return j;
    }
};