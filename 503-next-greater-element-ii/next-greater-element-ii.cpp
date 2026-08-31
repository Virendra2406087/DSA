class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;

        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            while (!s.empty() && nums[s.top()] <= nums[idx]) {
                s.pop();
            }
            if (i < n && !s.empty()) {
                ans[idx] = nums[s.top()];
            }
            s.push(idx);
        }

        return ans;
    }
};