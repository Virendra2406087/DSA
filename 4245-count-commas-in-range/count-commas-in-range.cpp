class Solution {
public:
    int digit(int n) {
        int count=0;
        while(n > 0 ) {
            n/=10;
            count++;
        }
        return count;
    }
    int countCommas(int n) {
        if(n <= 999) {
            return 0;
        }
        int count = 0;
        for(int i=1;i<=n;i++){
            int dig=digit(i);
            if(dig > 3){
               int comas=(dig - 1) / 3;
               count += comas;
            }
        }
        return count;
    }
};