class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for (int j = 0; j < n; j++) {
            int maxi = INT_MIN;
            int mini = INT_MAX;

            for (int i = 0; i <= j; i++)
                maxi = max(maxi, nums[i]);

            for (int i = j; i < n; i++)
                mini = min(mini, nums[i]);

            if ((long long)maxi - mini <= k)
                return j;
        }

        return -1;
    }
};