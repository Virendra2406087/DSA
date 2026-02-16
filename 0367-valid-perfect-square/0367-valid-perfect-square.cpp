class Solution {
public:
    bool isPerfectSquare(int num) {
        int target=num;
        int s=0;
        int e=target;
        while(s<=e){
            long long int mid=s+(e-s)/2;
            long long prod=mid*mid;
            if(prod==target){
                return true;
            }
            if(prod<target){
                s=mid+1;
            }
            if(prod>target){
                e=mid-1;
            }
        }
        return false;
    }
};