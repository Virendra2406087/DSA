#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='{'|| ch=='('|| ch=='['){
                st.push(ch);
            }else{
                if(st.empty()){
                    return false;
                }
                if(ch=='}' && st.top() !='{'){
                    return false;
                }
                if(ch==')' && st.top() !='('){
                    return false;
                }
                if(ch==']' && st.top() !='['){
                    return false;
                }else{
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};