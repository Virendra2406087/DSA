class Solution {
public:
    int longestValidParentheses(string s) {
        // int n = s.length();
        // int maxLen = 0;
        // stack<int> st;

        // // base index for valid substring
        // st.push(-1);

        // for(int i = 0; i < n; i++) {
        //     if(s[i] == '(') {
        //         st.push(i);
        //     } else {
        //         st.pop();
        //         if(st.empty()) {
        //             // reset base
        //             st.push(i);
        //         } else {
        //             maxLen = max(maxLen, i - st.top());
        //         }
        //     }
        // }
        // return maxLen;
        

        stack<int>st;
        int n=s.length();
        int maxLen=0;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    maxLen=max(maxLen,i-st.top());
                }
            }
        }
        return maxLen;
    }
};
