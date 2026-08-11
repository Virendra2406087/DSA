class Solution {
public:
    string minWindow(string s, string t) {
        int len1=s.length();
        int len2=t.length();
        if(len1<len2){
            return {};
        }
        int ansIndex=-1;
        int ansLen=INT_MAX;
        unordered_map<char,int>sMap;
        unordered_map<char,int>tMap;
        for(auto i:t){
            tMap[i]++;
        }
        int i=0,j=0;
        int count=0;
        while(j<len1){
            char ch=s[j];
            sMap[ch]++;
            if(sMap[ch]<=tMap[ch]){
                count++;
            }
            if(count==len2){
                while(sMap[s[i]]>tMap[s[i]]){
                    sMap[s[i]]--;
                    i++;
                }
                int windowLen=j-i+1;
                if(windowLen<ansLen){
                    ansLen=windowLen;
                    ansIndex=i;
                }
            }
            j++;
        }
        if(ansIndex==-1){
            return "";
        }else{
            return s.substr(ansIndex,ansLen);
        }
    }
};