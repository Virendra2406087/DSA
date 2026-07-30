class Solution {
public:
    int minimumPushes(string word) {
        int result=0;
        vector<int>mp(26,0);
        int assign=2;
        for(char &c:word){
            mp[c-'a']++;
        }
        sort(mp.begin(),mp.end(),greater<int>());
        for(int i=0;i<26;i++){
            int freq=mp[i];
            int press=(i/8+1);
            result+=press*freq;
        }
        return result;
    }
};