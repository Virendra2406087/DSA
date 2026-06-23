class Solution {
public:
    int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<vector<long long>> next(m, vector<long long>(2, 1));
        vector<vector<long long>> cur(m, vector<long long>(2));

        for (int pos = n - 1; pos >= 2; pos--) {

            vector<long long> pref0(m + 1, 0);
            vector<long long> pref1(m + 1, 0);

            for (int i = 0; i < m; i++) {
                pref0[i + 1] = (pref0[i] + next[i][0]) % MOD;
                pref1[i + 1] = (pref1[i] + next[i][1]) % MOD;
            }

            for (int v = 0; v < m; v++) {
                cur[v][0] = pref1[v];
                cur[v][1] =(pref0[m] - pref0[v + 1] + MOD) % MOD;
            }
            swap(cur, next);
        }

        long long ans = 0;

        for (int a = 0; a < m; a++) {
            for (int b = 0; b < m; b++) {

                if (a == b){
                    continue;
                } 

                if (a < b) {
                    ans = (ans + next[b][0]) % MOD;
                } else {
                    ans = (ans + next[b][1]) % MOD;
                }
            }
        }

        return (int)ans;
    }
};