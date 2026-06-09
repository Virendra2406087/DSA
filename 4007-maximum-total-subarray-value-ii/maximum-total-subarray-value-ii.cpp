class SparseTable {
public:
    int n, P;
    vector<vector<int>> st;
    function<int(int, int)> func;

    SparseTable(vector<int> &arr, function<int(int, int)> f) {
        n = arr.size();
        func = f;
        P = log2(n) + 1;

        st.assign(n, vector<int>(P));

        for (int i = 0; i < n; i++)
            st[i][0] = arr[i];

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = func(
                    st[i][j - 1],
                    st[i + (1 << (j - 1))][j - 1]
                );
            }
        }
    }

    int query(int L, int R) {
        int len = R - L + 1;
        int k = log2(len);

        return func(
            st[L][k],
            st[R - (1 << k) + 1][k]
        );
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        SparseTable mnst(nums, [](int a, int b) {
            return min(a, b);
        });

        SparseTable mxst(nums, [](int a, int b) {
            return max(a, b);
        });

        using T = tuple<long long, int, int>;

        priority_queue<T> pq;

        set<pair<int, int>> seen;

        int n = nums.size();

        long long val = 1LL * mxst.query(0, n - 1) - mnst.query(0, n - 1);

        pq.push({val, 0, n - 1});
        seen.insert({0, n - 1});

        long long ans = 0;

        while (k--) {

            auto [score, L, R] = pq.top();
            pq.pop();

            ans += score;

            if (L + 1 <= R && !seen.count({L + 1, R})) {
                seen.insert({L + 1, R});

                long long v =
                    1LL * mxst.query(L + 1, R) -
                    mnst.query(L + 1, R);

                pq.push({v, L + 1, R});
            }

            if (L <= R - 1 && !seen.count({L, R - 1})) {
                seen.insert({L, R - 1});

                long long v =
                    1LL * mxst.query(L, R - 1) -
                    mnst.query(L, R - 1);

                pq.push({v, L, R - 1});
            }
        }

        return ans;
    }
};