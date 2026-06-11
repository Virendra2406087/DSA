class Solution {
public:
    int M=1e9+7;
    int t[201][201][2];
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t,0,sizeof(t));
        t[0][0][1]=1;
        t[0][0][0]=1;
        for(int onesLeft=0;onesLeft<=one;onesLeft++){
            for(int zeroLeft=0;zeroLeft<=zero;zeroLeft++){
                if(onesLeft==0 && zeroLeft==0){
                    continue;
                }
                int result=0;
                for(int len=1;len<=min(zeroLeft,limit);len++){
                    result=(result+t[onesLeft][zeroLeft-len][0])%M;
                }
                t[onesLeft][zeroLeft][1]=result;
                result=0;
                for(int len=1;len<=min(onesLeft,limit);len++){
                    result=(result+t[onesLeft-len][zeroLeft][1])%M;
                }
                t[onesLeft][zeroLeft][0]=result;
            }
        }
        int startWithOne=t[one][zero][false];
        int startWithZero=t[one][zero][true];
        return (startWithOne + startWithZero)%M;
    }
};