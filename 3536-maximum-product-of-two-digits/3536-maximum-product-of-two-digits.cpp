class Solution {
public:
    int maxProduct(int n) {
        vector<int>digit;
        while(n>0){
            digit.push_back(n%10);
            n/=10;
        }
        sort(digit.begin(),digit.end());
        int m=digit.size();
        return digit[m-1]*digit[m-2];
    }
};