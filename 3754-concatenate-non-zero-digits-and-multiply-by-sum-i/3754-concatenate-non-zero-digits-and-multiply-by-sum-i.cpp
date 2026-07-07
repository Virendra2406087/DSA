class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int>digit;
        int sum=0;
        while(n>0){
            int val=n%10;
            if(val > 0){
                digit.push_back(val);
                sum+=val;
            }
            n=n/10;
        }
        reverse(digit.begin(),digit.end());
        long long totalVal=0;
        for(int i=0;i<digit.size();i++){
            totalVal=totalVal*10+digit[i];
        }
        long long ans=totalVal*sum;
        return ans;

    }
};