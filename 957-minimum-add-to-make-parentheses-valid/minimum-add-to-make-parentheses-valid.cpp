class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='('){
                st.push(ch);
            }else if(ch==')' && !st.empty() && st.top()=='('){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        int count=0;
        while(!st.empty()){
            char curr=st.top();
            st.pop();
            count++;
        }
        return count;
    }
};