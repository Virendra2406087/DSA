class SegmentTree {
private:
    int n;
    vector<int> values;
    vector<int> tree;

    void build(int node, int left, int right) {
        if (left == right) {
            tree[node] = values[left];
            return;
        }

        int mid = (left + right) / 2;

        build(node * 2, left, mid);
        build(node * 2 + 1, mid + 1, right);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int left, int right,
              int ql, int qr) {

        if (ql <= left && right <= qr)
            return tree[node];

        int mid = (left + right) / 2;
        int ans = 0;

        if (ql <= mid)
            ans = max(ans,
                      query(node * 2, left, mid, ql, qr));

        if (qr > mid)
            ans = max(ans,
                      query(node * 2 + 1, mid + 1, right,
                            ql, qr));

        return ans;
    }

public:
    SegmentTree(vector<int> &arr) {
        values = arr;
        n = arr.size();
        tree.assign(4 * max(1, n), 0);

        if (n > 0)
            build(1, 0, n - 1);
    }

    int query(int ql, int qr) {
        if (n == 0 || ql > qr)
            return 0;

        return query(1, 0, n - 1, ql, qr);
    }
};

class Solution {
public:
    int lowerBound(vector<int> &v, int target) {
        int l = 0, r = v.size();

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (v[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    int upperBound(vector<int> &v, int target) {
        int l = 0, r = v.size();

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (v[mid] <= target)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>> &queries) {

        int n = s.size();

        //------------------------------------------------------
        // Count total ones
        //------------------------------------------------------
        int totalOnes = 0;
        for (char c : s)
            if (c == '1')
                totalOnes++;

        //------------------------------------------------------
        // Store zero blocks
        //------------------------------------------------------
        vector<int> zeroBlockLength;
        vector<int> zeroBlockStart;
        vector<int> zeroBlockEnd;

        int i = 0;

        while (i < n) {
            int start = i;

            while (i < n && s[i] == s[start])
                i++;

            if (s[start] == '0') {
                zeroBlockLength.push_back(i - start);
                zeroBlockStart.push_back(start);
                zeroBlockEnd.push_back(i - 1);
            }
        }

        int blockCount = zeroBlockLength.size();

        vector<int> answer;

        //------------------------------------------------------
        // Less than two zero blocks
        //------------------------------------------------------
        if (blockCount < 2) {
            for (auto &q : queries)
                answer.push_back(totalOnes);

            return answer;
        }

        //------------------------------------------------------
        // pairSum
        //------------------------------------------------------
        vector<int> pairSum(blockCount - 1);

        for (int i = 0; i < blockCount - 1; i++)
            pairSum[i] = zeroBlockLength[i] +
                         zeroBlockLength[i + 1];

        SegmentTree seg(pairSum);

        //------------------------------------------------------
        // Answer queries
        //------------------------------------------------------
        for (auto &q : queries) {

            int left = q[0];
            int right = q[1];

            int firstBlock =
                lowerBound(zeroBlockEnd, left);

            int lastBlock =
                upperBound(zeroBlockStart, right) - 1;

            if (firstBlock > blockCount - 1 ||
                lastBlock < 0 ||
                firstBlock >= lastBlock) {

                answer.push_back(totalOnes);
                continue;
            }

            int firstLength =
                zeroBlockEnd[firstBlock] -
                max(zeroBlockStart[firstBlock], left) + 1;

            int lastLength =
                min(zeroBlockEnd[lastBlock], right) -
                zeroBlockStart[lastBlock] + 1;

            if (firstBlock + 1 == lastBlock) {
                answer.push_back(totalOnes +
                                 firstLength +
                                 lastLength);
                continue;
            }

            int option1 =
                firstLength +
                zeroBlockLength[firstBlock + 1];

            int option2 =
                zeroBlockLength[lastBlock - 1] +
                lastLength;

            int option3 =
                seg.query(firstBlock + 1,
                          lastBlock - 2);

            int bestGain =
                max({option1, option2, option3});

            answer.push_back(totalOnes + bestGain);
        }

        return answer;
    }
};