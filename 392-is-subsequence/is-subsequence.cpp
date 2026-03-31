class Solution {
public:
    bool solve(string s,string t,int i,int j){
        if(i>=s.length()){
            return true;
        }
        if(j>=t.length()){
            return false;
        }
        if(s[i]==t[j]){
            return solve(s,t,i+1,j+1);
        }else{
            return solve(s,t,i,j+1);
        }
    }
    bool isSubsequence(string s, string t) {
        return solve(s,t,0,0);
    }
};