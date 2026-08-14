class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0,j=0;
        int n=s.length();
        vector<int>freq(26,0);
        int result=0;
        while(j<n){
            int index=s[j]-'a';
            freq[index]++;
            while(freq[index]>2){
                freq[s[i]-'a']--;
                i++;
            }
            result=max(result,j-i+1);
            j++;
        }
        return result;
    }
};