class Solution {
public:
    bool checkDivisibility(int n) {
        int val=n;
        int digitSum=0;
        int product=1;
        while(val > 0){
            int digit=val%10;
            digitSum+=digit;
            product*=digit;
            val/=10;
        }
        int sum=digitSum+product;
        return n%sum==0;
    }
};