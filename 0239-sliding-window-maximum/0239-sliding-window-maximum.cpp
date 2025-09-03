class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // process
        deque<int> dq;
        vector<int> ans;

        // first window
        for (int index = 0; index < k; index++) {
            // addition
            while (!dq.empty() && nums[dq.back()] < nums[index]) {
                dq.pop_back();
            }
            dq.push_back(index);
        }
        // answer for first window
        int element = nums[dq.front()];
        ans.push_back(element);

        // remaining windows
        for (int i = k; i < nums.size(); i++) {
            // remove out of window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            // addition
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // answer
            int element = nums[dq.front()];
            ans.push_back(element);
        }

        return ans;
    }
};
