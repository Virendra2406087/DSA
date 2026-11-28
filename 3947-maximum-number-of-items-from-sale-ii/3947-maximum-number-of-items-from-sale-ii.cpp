class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Count frequency of each factor
        vector<int> freq(n + 1, 0);

        for (auto& item : items) {
            freq[item[0]]++;
        }

        // Calculate how many free items each factor can unlock
        vector<int> gain(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                gain[i] += freq[j];
            }
            gain[i]--; // Exclude the item itself
        }

        // Find minimum price
        int minPrice = INT_MAX;

        for (auto& item : items) {
            minPrice = min(minPrice, item[1]);
        }

        // Sort items by price
        sort(items.begin(), items.end(),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long remaining = budget;

        // Greedily purchase items that provide 2 copies
        for (auto& item : items) {
            long long factor = item[0];
            long long price = item[1];

            // Buying at this price is not beneficial
            if (price > 2LL * minPrice)
                break;

            long long capacity = gain[factor];

            // Maximum number of purchases possible
            long long cnt = min(capacity, remaining / price);

            ans += 2 * cnt;
            remaining -= cnt * price;
        }

        // Spend remaining budget on cheapest items
        ans += remaining / minPrice;

        return (int)ans;
    }
};