class Solution {
public:
    int digitProduct(int n){
        int product=1;
        while(n>0){
            product*=n%10;
            n/=10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        int prd=digitProduct(n);
        while(digitProduct(n)%t !=0){
            n++;
        }
        return n;;
    }
};