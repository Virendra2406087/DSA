class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < nums[0].size(); i++) {
            int target = nums[0][i];
            int count = 0;

            for (int j = 1; j < n; j++) {
                bool found = false;
                for (int k = 0; k < nums[j].size(); k++) {
                    if (nums[j][k] == target) {
                        found = true;
                        break;
                    }
                }
                if (found) count++;
            }

            if (count == n - 1)
                ans.push_back(target);
        }

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
