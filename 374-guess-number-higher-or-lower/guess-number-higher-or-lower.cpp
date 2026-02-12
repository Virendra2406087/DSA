/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long int s=1;
        long int e=n;
        long int mid;
        while(s<=e){
            mid=(s+e)/2;
            long int g=guess(mid);
            if(g==0){
                return mid;
            }else if(g==-1){
                e=mid-1;
            }else{
                s=mid+1;;
            }
        }
        return -1;
    }
};