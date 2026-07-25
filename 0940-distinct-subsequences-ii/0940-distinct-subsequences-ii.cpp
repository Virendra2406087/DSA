class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> last(26, 0);
        long long total = 1;  

        for (char c : s) {
            long long newTotal = (2 * total - last[c - 'a'] + MOD) % MOD;
            last[c - 'a'] = total;
            total = newTotal;
        }

        return (total - 1 + MOD) % MOD;
    }
};