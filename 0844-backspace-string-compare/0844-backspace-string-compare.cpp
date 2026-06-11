class Solution {
public:
    string minimize(string s){
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(s[i]);
            }
        }
        string ans;
        stack<char> rev;

        while (!st.empty()) {
            rev.push(st.top());
            st.pop();
        }
        while(!rev.empty()){
            ans+=rev.top();
            rev.pop();
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        string ans1=minimize(s);
        string ans2=minimize(t);
        int n=ans1.size();
        int m=ans2.size();
        if(n==m){
           for(int i=0;i<n;i++){
            if(ans1[i] != ans2[i]){
                return false;
            }
           }
           return true;
        }else{
            return false;
        }
    }
};