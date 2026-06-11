class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(!st.empty()){
                if(s[i]==st.top()){
                    st.pop();
                }
                else{
                st.push(s[i]);
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