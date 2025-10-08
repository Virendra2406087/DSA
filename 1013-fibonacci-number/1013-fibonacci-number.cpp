class Solution {
public:
    int solveusingRec(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int fib=solveusingRec(n-1)+solveusingRec(n-2);
        return fib;
    }
    int fib(int n) {
        int ans=solveusingRec(n);
        return ans;
  }
};