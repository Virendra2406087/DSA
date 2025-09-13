class Solution {
public:
    
    int revere(int x){
        if(x<0){
            return false;
        }
        long long int sum=0;
        while(x !=0){
            int digit=x%10;
            sum=sum*10+digit;
            x=x/10;
        }
        if(sum>INT_MAX || sum<INT_MIN){
            return false;
        }
        return sum;
    }
    bool isPalindrome(int x) {
        int rev=revere(x);
        if(rev==x){
            return true;
        }
        return false;
    }
};