class Solution {
public:
    void store(string s, vector<int>& ans) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                int num = 0;

                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                ans.push_back(num);
            }
        }
    }

    bool areNumbersAscending(string s) {
        vector<int> ans;
        store(s, ans);

        int n = ans.size();

        for (int i = 0; i < n - 1; i++) {
            if (ans[i] >= ans[i + 1]) {
                return false;
            }
        }

        return true;
    }
};