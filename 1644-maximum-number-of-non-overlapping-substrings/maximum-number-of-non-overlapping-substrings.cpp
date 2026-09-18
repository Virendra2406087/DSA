class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find first and last occurrence
        for(int i = 0; i < n; i++) {
            int ch = s[i] - 'a';

            first[ch] = min(first[ch], i);
            last[ch] = i;
        }

        vector<pair<int,int>> intervals;

        // Try to make a valid interval for every character
        for(int ch = 0; ch < 26; ch++) {

            if(last[ch] == -1)
                continue;

            int l = first[ch];
            int r = last[ch];

            bool valid = true;

            for(int i = l; i <= r; i++) {
                int curr = s[i] - 'a';

                // This character occurs before our interval
                if(first[curr] < l) {
                    valid = false;
                    break;
                }

                r = max(r, last[curr]);
            }

            if(valid) {
                intervals.push_back({l, r});
            }
        }

        // Sort according to ending position
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        for(auto &interval : intervals) {
            int l = interval.first;
            int r = interval.second;

            if(l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};