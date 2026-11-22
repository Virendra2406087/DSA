class Solution {
public:
    bool checkString(string s) {
        bool presB=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                presB=true;
            }
            if(s[i]=='a' && presB==true) {
                return false;
            }
        }
        return true;
    }
};