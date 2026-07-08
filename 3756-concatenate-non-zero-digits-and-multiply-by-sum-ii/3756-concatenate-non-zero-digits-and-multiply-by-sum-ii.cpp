class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int l, int r,vector<long long> &prefSum,vector<int> &pos,vector<long long> &prefNum,vector<long long> &pow10) {

        long long sum = prefSum[r + 1] - prefSum[l];

        int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
        int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin();

        long long x = 0;

        if (L < R) {
            int len = R - L;
            x = (prefNum[R] - prefNum[L] * pow10[len] % MOD + MOD) % MOD;
        }

        return (x * (sum % MOD)) % MOD;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> prefSum(n + 1, 0);
        vector<int> pos, digit;

        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i];
            if (s[i] != '0') {
                prefSum[i + 1] += s[i] - '0';
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> prefNum(m + 1, 0);
        for (int i = 0; i < m; i++)
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % MOD;

        vector<int> ans;

        for (auto &q : queries) {
            ans.push_back(solve(q[0], q[1], prefSum, pos, prefNum, pow10));
        }

        return ans;
    }
};