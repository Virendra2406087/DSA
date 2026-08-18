#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        // Step 1: Collect unique points (requests + start) and sort them
        vector<int> p = requests;
        p.push_back(start);
        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
        
        int k = p.size() - 1;
        
        // Step 2: Mark which points are actual requests
        vector<int> is_req(p.size(), 0);
        for (int r : requests) {
            int idx = lower_bound(p.begin(), p.end(), r) - p.begin();
            is_req[idx] = 1;
        }
        
        // Prefix sum of requests for range query counting
        vector<int> pref(p.size() + 1, 0);
        for (int i = 0; i <= k; ++i) {
            pref[i + 1] = pref[i] + is_req[i];
        }
        
        auto count_reqs = [&](int l, int r) {
            return pref[r + 1] - pref[l];
        };
        
        int total_reqs = requests.size();
        auto unfulfilled_outside = [&](int l, int r) {
            return total_reqs - count_reqs(l, r);
        };
        
        int s = lower_bound(p.begin(), p.end(), start) - p.begin();
        
        // Step 3: DP Table initialization
        // dp[i][j][0]: elevator at p[i]
        // dp[i][j][1]: elevator at p[j]
        const long long INF = 1e18;
        vector<vector<vector<long long>>> dp(k + 1, vector<vector<long long>>(k + 1, vector<long long>(2, INF)));
        
        dp[s][s][0] = 0;
        dp[s][s][1] = 0;
        
        // Step 4: Interval DP
        for (int len = 0; len <= k; ++len) {
            for (int i = 0; i + len <= k; ++i) {
                int j = i + len;
                long long outside_count = unfulfilled_outside(i, j);
                
                // From end_pos = 0 (at p[i])
                if (dp[i][j][0] != INF) {
                    // Move left to i - 1
                    if (i > 0) {
                        long long cost = (long long)(p[i] - p[i - 1]) * outside_count;
                        dp[i - 1][j][0] = min(dp[i - 1][j][0], dp[i][j][0] + cost);
                    }
                    // Move right to j + 1
                    if (j < k) {
                        long long cost = (long long)(p[j + 1] - p[i]) * outside_count;
                        dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][0] + cost);
                    }
                }
                
                // From end_pos = 1 (at p[j])
                if (dp[i][j][1] != INF) {
                    // Move left to i - 1
                    if (i > 0) {
                        long long cost = (long long)(p[j] - p[i - 1]) * outside_count;
                        dp[i - 1][j][0] = min(dp[i - 1][j][0], dp[i][j][1] + cost);
                    }
                    // Move right to j + 1
                    if (j < k) {
                        long long cost = (long long)(p[j + 1] - p[j]) * outside_count;
                        dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][1] + cost);
                    }
                }
            }
        }
        
        return min(dp[0][k][0], dp[0][k][1]);
    }
};