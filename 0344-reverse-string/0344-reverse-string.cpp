class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        stack<char>st;
        while(i<s.size()){
            st.push(s[i]);
            i++;
        }
        s.clear();
        while(!st.empty()){
             char front=st.top();
             s.push_back(front);
             st.pop();
        }
    }
};