class Solution {
public:
    char findTheDifference(string s, string t) {
        char x=0;
        for(char ch:s){
            x^=ch;
        }
        for(char ch:t){
            x^=ch;
        }
        return x;
    }
};