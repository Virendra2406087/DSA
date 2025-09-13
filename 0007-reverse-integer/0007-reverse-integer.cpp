class Solution {
public:
    int reverse(int x) {
        long long int sum=0;
        while(x !=0){
        int digit=x%10;
        sum=sum*10+digit;
        x=x/10;
        }
        if (sum > INT_MAX || sum < INT_MIN) {
                return 0;
            }

        return sum;
    }
};