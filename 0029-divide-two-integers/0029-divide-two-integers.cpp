class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }

        long long divid = llabs((long long)dividend);
        long long divis = llabs((long long)divisor);
        long long ans=divid/divis;
        if(dividend<0 && divisor<0){
            return ans;
        }
        else if(dividend<0 && divisor>0){
            return -ans;
        }
        else if(dividend>0 && divisor<0){
            return -ans;
        }
        return ans;
    }
};