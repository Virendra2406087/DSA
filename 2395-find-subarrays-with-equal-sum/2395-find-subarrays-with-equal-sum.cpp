class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> seen;

        for(int i = 0; i < nums.size() - 1; i++) {
            int sum = nums[i] + nums[i + 1];

            if(seen.count(sum)) {
                return true;
            }

            seen.insert(sum);
        }

        return false;
    }
};