class Solution {
public:
    int solveUsingRec(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int ans=solveUsingRec(n-1)+solveUsingRec(n-2);
        return ans;
    }
    int fib(int n) {
        int ans=solveUsingRec(n);
        return ans;
    }
};