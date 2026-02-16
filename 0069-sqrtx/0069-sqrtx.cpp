class Solution {
public:
    int mySqrt(int x) {
        int target=x;
        int s=0;
        int e=target;
        int ans=-1;
        while(s<=e){
            long long int mid=s+(e-s)/2;
            long long int prod=mid*mid;
            if(prod==target){
                return mid;
            }
            if(prod>target){
                e=mid-1;
            }
            if(prod<target){
                ans=mid;
                s=mid+1;
            }
        }
        return ans;
        }
};