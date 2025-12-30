class Solution {
public:
    void solve(string &s, int i, int k) {
        if (i >= s.length()) return;

        int j = min(i + k - 1, (int)s.length() - 1);

        int l = i, r = j;
        while (l < r) {
            swap(s[l++], s[r--]);
        }

        solve(s, i + 2*k, k);
    }

    string reverseStr(string s, int k) {
        solve(s, 0, k);
        return s;
    }
};
