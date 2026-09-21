class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for(int i=0;i<nums.size();i++) {

            vector<long long> newdp(k, 0);

            // Start a new subarray
            int rem = nums[i] % k;
            newdp[rem]++;

            // Extend previous subarrays
            for(int j=0;j<k;j++) {

                if(dp[j] == 0) {
                    continue;
                }

                int newRem = (j * rem) % k;

                newdp[newRem] += dp[j];
            }

            dp = newdp;

            // Add subarrays ending at i
            for(int j=0;j<k;j++) {
                ans[j] += dp[j];
            }
        }

        return ans;
    }
};