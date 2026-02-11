class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevSmaller(n), nextSmaller(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;
            ans = (ans + arr[i] * left * right) % MOD;
        }

        return ans;
    }
};
