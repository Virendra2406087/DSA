class Solution {
public:
    string minWindow(string s, string t) {
        int len1=s.length();
        int len2=t.length();
        if(len1<len2){
            return "";
        }
        int ansIndex=-1;
        int ansLen=INT_MAX;
        unordered_map<char,int>sMap;
        unordered_map<char,int>tMap;
        for(auto i:t){
            tMap[i]++;
        }
        int start=0;
        int end=0;
        int count=0;
        while(end<s.length()){
            char ch=s[end];
            sMap[ch]++;
            if(sMap[ch] <= tMap[ch]){
                count++;
            }
            if(count==len2){
                while(sMap[s[start]]>tMap[s[start]]){
                    sMap[s[start]]--;
                    start++;
                }
                int windowLength=end-start+1;
                if(windowLength<ansLen){
                    ansLen=windowLength;
                    ansIndex=start;
                }
            }
            end++;
        }
        if(ansIndex==-1){
            return "";
        }else{
            return s.substr(ansIndex,ansLen);
        }
    }
};