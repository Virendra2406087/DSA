class Solution {
public:
    int fibUsingRec(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int  ans=fibUsingRec(n-1)+fibUsingRec(n-2);
        return ans;
    }
    int fib(int n) {
        
        int  ans=fibUsingRec(n);
        return ans;
    }
};