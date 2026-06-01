class Solution {
public:
    bool canForm(vector<int>& nums, int p, int maxDiff) {
        int pairs = 0;

        for (int i = 0; i < nums.size() - 1; ) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                pairs++;
                i += 2;
            } else {
                i++;
            }
        }

        return pairs >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back() - nums.front();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canForm(nums, p, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};