class Solution {
public:
    using int64 = long long;
    const int64 LIM = (long long)1e15;

    char processStr(string s, long long k) {
        int n = s.size();
        vector<int64> len(n + 1, 0);
        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') {
                len[i + 1] = min(LIM, len[i] + 1);
            }
            else if (ch == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (ch == '#') {
                if (len[i] >= LIM / 2)
                    len[i + 1] = LIM;
                else
                    len[i + 1] = min(LIM, len[i] * 2);
            }
            else { // '%'
                len[i + 1] = len[i];
            }
        }
        if (k >= len[n]) {
            return '.';
        }
        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') {
                if (k == len[i]) {
                    return ch;
                }
            }
            else if (ch == '*') {
            }
            else if (ch == '#') {
                if (k >= len[i]) {
                    k -= len[i];
                }
            }
            else { // '%'
                if (len[i] > 0) {
                    k = len[i] - 1 - k;
                }
            }
        }

        return '.';
    }
};