class Solution {
public:
    int solve(int amount, int index, vector<int> &coins, vector<vector<int>> &dp) {
        // base case
        if (amount == 0) return 1;
        if (index >= coins.size()) return 0;

        // already computed
        if (dp[index][amount] != -1) return dp[index][amount];

        int include = 0;
        if (coins[index] <= amount) {
            include = solve(amount - coins[index], index, coins, dp);
        }
        int exclude = solve(amount, index + 1, coins, dp);

        return dp[index][amount] = include + exclude;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return solve(amount, 0, coins, dp);
    }
};
