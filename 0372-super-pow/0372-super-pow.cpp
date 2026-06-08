class Solution {
public:
    static const int MOD = 1337;

    int modPow(int a, int n) {
        int res = 1;
        a %= MOD;

        while (n > 0) {
            if (n & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            n >>= 1;
        }

        return res;
    }

    int superPow(int a, vector<int>& b) {
        int ans = 1;

        for (int digit : b) {
            ans = modPow(ans, 10);
            ans = (ans * modPow(a, digit)) % MOD;
        }

        return ans;
    }
};