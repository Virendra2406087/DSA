class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> seen;
        int count = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            count++;

            if (nums[i] <= k){
                seen.insert(nums[i]);
            }

            if (seen.size() == k){
                return count;
            }
        }

        return count;
    }
};