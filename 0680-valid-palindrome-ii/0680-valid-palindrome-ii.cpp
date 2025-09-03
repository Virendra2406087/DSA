class Solution {
public:
bool checkValid(string s ,int i,int j){
    while(i<=j){
        if(s[i] !=s[j]){
            return  false;
        }else{
            i++;
            j--;
        }
    }
    return true;
}
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                bool firstcase=checkValid(s,i+1,j);
                bool secondcase=checkValid(s,i,j-1);
                bool finalans=firstcase || secondcase;
                return finalans;
            }
        }
        return true;
        
    }
};