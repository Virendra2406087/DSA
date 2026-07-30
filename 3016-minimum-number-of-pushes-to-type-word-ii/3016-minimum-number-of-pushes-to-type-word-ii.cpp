class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0);
        for(char &c:word){
            mp[c-'a']++;
        }
        int result=0;
        sort(mp.begin(),mp.end(),greater<int>());
        for(int i=0;i<26;i++){
            int freq=mp[i];
            int press=i/8+1;
            result+=press*freq;
        }
        return result;
    }
};