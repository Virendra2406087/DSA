class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> st;

        for(int i = 0; i < digits.size(); i++) {
            if(digits[i] == 0) {
                continue;
            }

            for(int j = 0; j < digits.size(); j++) {
                if(j == i) {
                    continue;
                }

                for(int k = 0; k < digits.size(); k++) {
                    if(k == i || k == j) {
                        continue;
                    }

                    if(digits[k] % 2 != 0) {
                        continue;
                    }

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];

                    st.insert(num);
                }
            }
        }

        vector<int>ans;
        for(auto num : st) {
            ans.push_back(num);
        }
        return ans;
    }
};