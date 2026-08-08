class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> last(m, -1);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;

                if (j < 0)
                    break;
            }
        }

        bool change = false;
        j = 0;

        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (j == m)
                break;

            if (word1[i] == word2[j]) {
                res.push_back(i);
                j++;
            }
            else if (!change && (j == m - 1 || last[j + 1] > i)) {
                change = true;
                res.push_back(i);
                j++;
            }
        }

        return res.size() == m ? res : vector<int>{};
    }
};