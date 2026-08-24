class Solution {
public:

    using ull = unsigned long long;
    ull splitmix64(ull x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }

    vector<int> getLeft(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> left(n);

        vector<int> freq(100001, 0);

        int distinct = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {

            if (freq[nums[r]] == 0)
                distinct++;

            freq[nums[r]]++;

            while (distinct > k) {
                freq[nums[l]]--;

                if (freq[nums[l]] == 0)
                    distinct--;

                l++;
            }

            left[r] = l;
        }

        return left;
    }

    vector<bool> validSubarrays(vector<int>& nums,
                                int k,
                                vector<vector<int>>& queries) {

        int n = nums.size();
        vector<int> leftK = getLeft(nums, k);
        vector<int> leftKMinus1 = getLeft(nums, k - 1);
        vector<ull> h1(100001);
        vector<ull> h2(100001);

        for (int x = 1; x <= 100000; x++) {
            h1[x] = splitmix64(x);
            h2[x] = splitmix64(x + 1000000007ULL);
        }

        vector<pair<ull, ull>> state(n + 1);

        ull cur1 = 0;
        ull cur2 = 0;

        state[0] = {0, 0};

        for (int i = 0; i < n; i++) {

            cur1 ^= h1[nums[i]];
            cur2 ^= h2[nums[i]];

            state[i + 1] = {cur1, cur2};
        }
        map<pair<ull, ull>, vector<int>> positions;

        for (int i = 0; i <= n; i++) {
            positions[state[i]].push_back(i);
        }

        vector<bool> answer;

        for (auto& query : queries) {

            int l = query[0];
            int r = query[1];
            if (l < leftK[r] || l >= leftKMinus1[r]) {
                answer.push_back(false);
                continue;
            }
            auto it = positions.find(state[r + 1]);

            if (it == positions.end()) {
                answer.push_back(false);
                continue;
            }
            answer.push_back(state[l] == state[r + 1]);
        }

        return answer;
    }
};