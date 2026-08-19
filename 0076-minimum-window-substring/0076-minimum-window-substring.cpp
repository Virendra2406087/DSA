class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        if(len1 < len2){
            return {};
        }
        int ansLen = INT_MAX;
        int ansIndex = -1;
        unordered_map <char,int> sMap;
        unordered_map <char,int> tMap;
        for(int i = 0;i<len2;i++){
            tMap[t[i]]++;
        }
        int i=0,j=0;
        int count = 0;
        while(j<len1){
            sMap[s[j]]++;
            if(sMap[s[j]] <= tMap[s[j]]){
                count++;
            }
            if (count==len2){
                while(sMap[s[i]]>tMap[s[i]]) {
                    sMap[s[i]]--;
                    i++;
                }
                int windowLen = j-i+1;
                if(windowLen < ansLen){
                    ansLen=windowLen;
                    ansIndex = i;
                }
            }
            j++;
        }
        if (ansIndex == -1) {
            return "";
        } else {
            return s.substr(ansIndex,ansLen);
        }


    }
};