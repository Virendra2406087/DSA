class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> st;

        int n = nums.size();
        int i = 0, j = 0;

        while (j < n) {
            if (j - i > indexDiff) {
                st.erase(nums[i]);
                i++;
            }
            auto it = st.lower_bound((long long)nums[j] - valueDiff);
            if (it != st.end() &&
                *it <= (long long)nums[j] + valueDiff) {
                return true;
            }

            st.insert(nums[j]);
            j++;
        }

        return false;
    }
};