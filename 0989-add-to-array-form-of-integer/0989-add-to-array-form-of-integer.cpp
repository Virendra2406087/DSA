class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
         vector<int> ans;
        int i = num.size() - 1;

        while(i >= 0 || k > 0){
            if(i >= 0){
                k += num[i];
                i--;
            }
            int digit = k % 10;
            k = k / 10;
            ans.push_back(digit);
        }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};