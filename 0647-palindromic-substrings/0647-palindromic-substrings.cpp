class Solution {
public:

    int checkpalindrome(string s,int i,int j){
        int count=0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
           count++;
           i--;
           j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count=0;
        for(int center=0;center<s.length();center++){
            int i=center;
            int j=center;
            int oddcount=checkpalindrome(s,i,j);
             i=center;
             j=center+1;
            int evencount=checkpalindrome(s,i,j);
            count=count+evencount+oddcount;
        }
        return count;
    }
};