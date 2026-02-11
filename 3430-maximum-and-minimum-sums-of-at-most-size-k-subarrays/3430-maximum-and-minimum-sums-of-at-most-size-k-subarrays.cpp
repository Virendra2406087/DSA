class Solution {
public:

    long long countValid(long long L, long long R, long long k) {
        long long x = min(L, k);
        long long y = min(R, k);

        if (x + y <= k + 1)
            return x * y;

        long long t = k - y + 1;
        long long part1 = y * t;
        long long len = x - t;
        long long part2 = len * (k - t + k - x + 1) / 2;

        return part1 + part2;
    }

    void getMinContribution(vector<int>& nums, int k, vector<long long>& minVec) {
        int n = nums.size();
        vector<int> ple(n), nle(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            long long L = i - ple[i];
            long long R = nle[i] - i;
            minVec[i] = nums[i] * countValid(L, R, k);
        }
    }

    void getMaxContribution(vector<int>& nums, int k, vector<long long>& maxVec) {
        int n = nums.size();
        vector<int> pge(n), nge(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            long long L = i - pge[i];
            long long R = nge[i] - i;
            maxVec[i] = nums[i] * countValid(L, R, k);
        }
    }

    long long minMaxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> minVec(n), maxVec(n);

        getMinContribution(nums, k, minVec);
        getMaxContribution(nums, k, maxVec);

        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += minVec[i] + maxVec[i];

        return ans;
    }
};
