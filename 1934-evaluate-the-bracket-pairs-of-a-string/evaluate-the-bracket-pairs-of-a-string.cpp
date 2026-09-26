class Solution {
public: 
    bool isAlpha(char c){
        if(c >= 'a' && c <= 'z') {
            return true;
        }
        return false;
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        string result="";
        int i=0;
        int n=s.size();
        while(i<n){
            if(isAlpha(s[i])){
                result.push_back(s[i]);
            } else {
                i++;
                string temp ="";
                while(i < n && s[i] != ')') {
                    temp.push_back(s[i]);
                    i++;
                }
                result+=mp.count(temp) ? mp[temp] : "?";
            }
            i++;
        }
        return result;
    }
};