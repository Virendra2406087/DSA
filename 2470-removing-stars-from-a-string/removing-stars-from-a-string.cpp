class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                if (!st.empty()) {
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
};