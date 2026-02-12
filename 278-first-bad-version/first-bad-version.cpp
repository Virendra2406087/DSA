// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int s=1;
        long int e=n;
        long int mid;
        long int result=n;
        while(s<=e){
            mid=(s+e)/2;
            if(isBadVersion(mid)){
                result=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return result;
    }
};