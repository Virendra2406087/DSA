class Solution {
public:
    int minSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        int B = 17;
        int FULL = (1 << B) - 1;

        vector<int> cnt(B, 0);
        vector<bool> present(1 << B, false);

        // Build the first window
        for (int i = 0; i < k; i++) {
            for (int b = 0; b < B; b++) {
                if (nums[i] & (1 << b))
                    cnt[b]++;
            }
        }

        // Process all sliding windows
        for (int i = 0; i <= n - k; i++) {

            int mask = 0;

            for (int b = 0; b < B; b++) {
                if (cnt[b] == k)
                    mask |= (1 << b);
            }

            // If any window AND is zero, impossible
            if (mask == 0)
                return -1;

            present[mask] = true;

            // Remove outgoing element
            if (i + k < n) {
                for (int b = 0; b < B; b++) {
                    if (nums[i] & (1 << b))
                        cnt[b]--;
                }

                // Add incoming element
                for (int b = 0; b < B; b++) {
                    if (nums[i + k] & (1 << b))
                        cnt[b]++;
                }
            }
        }

        // Subset DP
        vector<bool> bad(1 << B, false);

        for (int mask = 0; mask <= FULL; mask++) {
            bad[mask] = present[mask];
        }

        for (int b = 0; b < B; b++) {
            for (int mask = 0; mask <= FULL; mask++) {
                if (mask & (1 << b)) {
                    bad[mask] = bad[mask] ||
                                bad[mask ^ (1 << b)];
                }
            }
        }

        // Find minimum set bits
        int ans = B;

        for (int y = 1; y <= FULL; y++) {
            int complement = FULL ^ y;

            if (!bad[complement]) {
                ans = min(ans, __builtin_popcount(y));
            }
        }

        return ans;
    }
};