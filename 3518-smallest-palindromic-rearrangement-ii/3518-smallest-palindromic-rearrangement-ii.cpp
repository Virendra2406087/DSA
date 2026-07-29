class Solution {
public:
    static const int LIMIT=1000000;
    long long comb(int n,int r){
        if(r<0 || r>n){
            return 0;
        }
        r=min(r,n-r);
        long long res=1;
        for(int i=1;i<=r;i++){
            res=res*(n-r+i)/i;
            if(res>=LIMIT){
                return LIMIT;
            }
        }
        return res;
    }
    long long countWays(vector<int>&cnt){
        int left=accumulate(cnt.begin(),cnt.end(),0);
        long long ways=1;
        for(int x:cnt){
            if(!x){
                continue;
            }
            ways*=comb(left,x);
            if(ways>=LIMIT){
                return LIMIT;
            }
            left-=x;
        }
        return ways;
    }
    string smallestPalindrome(string s, int k) {
        vector<int>freq(26),half(26);
        char mid=0;
        for(char c:s){
            freq[c-'a']++;
        }
        for(int i=0;i<26;i++){
            half[i]=freq[i]/2;
            if(freq[i] & 1){
                mid='a'+i;
            }
        }
        if(countWays(half)<k){
            return "";
        }
        string first;
        int len=s.size()/2;
        while((int)first.size()<len){
            for(int c=0;c<26;c++){
                if(!half[c]){
                    continue;
                }
                half[c]--;
                long long ways=countWays(half);
                if(ways>=k){
                    first+=char('a'+c);
                    break;
                }
                k-=ways;
                half[c]++;
            }
        }
        string second=first;
        reverse(second.begin(),second.end());
        return first+(mid?string(1,mid):"")+second;
    }
};