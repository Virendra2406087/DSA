class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> dp(budget + 1, 0);
        int minPrice = INT_MAX;

        for (auto &item : items) {
            int factor = item[0];
            int price = item[1];

            minPrice = min(minPrice, price);

            // Count items whose factors are divisible by factor
            int cnt = 0;

            for (auto &other : items) {
                if (other[0] % factor == 0) {
                    cnt++;
                }
            }

            // 0/1 Knapsack: first purchase of this item
            for (int j = budget; j >= price; j--) {
                dp[j] = max(dp[j], dp[j - price] + cnt);
            }
        }

        int ans = 0;

        // Spend remaining budget on the cheapest item
        for (int i = 0; i <= budget; i++) {
            ans = max(ans, dp[i] + (budget - i) / minPrice);
        }

        return ans;
    }
};