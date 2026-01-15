class Solution {
public:
    int getSum(int a, int b) {
        int carry=0;
        int sum=0;
        sum=sum+a+b+carry;
        carry=sum%10;
        return sum;
    }
};