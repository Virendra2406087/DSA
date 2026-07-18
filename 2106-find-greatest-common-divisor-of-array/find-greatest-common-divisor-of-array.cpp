class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int x:nums){
            if(x>maxi){
                maxi=x;
            }
            if(x<mini){
                mini=x;
            }
        }
        return gcd(maxi,mini);
    }
};