class Solution {
public:
    bool isValid(int x,long long mid){
        long long product=mid*mid;
        if(product==x){
            return true;
        }else{
            return false;
        }
    }
    int mySqrt(int x) {
        if(x==0 || x==1){
            return x;
        }
        int s=0;
        int e=x;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            long long product=1LL*mid*mid;
            if(isValid(x,mid)){
                return mid;
            }
            if(product<x){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
};