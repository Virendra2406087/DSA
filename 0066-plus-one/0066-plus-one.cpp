class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size() - 1;
        int carry = 1;

        for(int i = n; i >= 0; i--){
            int sum = digits[i] + carry;
            carry = sum / 10;
            ans.push_back(sum % 10);  
        }

        if(carry){
            ans.push_back(carry);    
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
