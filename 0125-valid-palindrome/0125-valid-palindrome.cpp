class Solution {
public:
    bool isValid(char ch) {
        if(ch >= 'a' && ch <= 'z'){
            return true;
        }
         if(ch >= 'A' && ch <= 'Z'){
            return true;
         }
        if(ch >= '0' && ch <= '9'){
            return true;
        }
        return false;
    }

    string normalstring(string s) {
        string newString = "";
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (isValid(ch)) {
                
                if (ch >= 'A' && ch <= 'Z') {
                    ch = ch - 'A' + 'a';
                }
                newString.push_back(ch);
            }
        }
        return newString;
    }

    bool isPalindrome(string s) {
        string newstr = normalstring(s);
        int i = 0;
        int e = newstr.size() - 1;
        while (i <= e) {
            if (newstr[i] != newstr[e]) {
                return false;
            }
            i++;
            e--;
        }
        return true;
    }
};
