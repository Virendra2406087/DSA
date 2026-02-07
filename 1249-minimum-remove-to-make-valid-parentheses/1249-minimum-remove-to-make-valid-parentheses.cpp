class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        stack<int>st;
        set<int>removeIndex;
        for(int i=0;i<n;i++){
           if(s[i]=='('){
            st.push(i);
           }else if(s[i]==')'){
            if(st.empty()){
            removeIndex.insert(i);
            }else{
            st.pop();
           }
           }
        }
        while(!st.empty()){
            removeIndex.insert(st.top());
            st.pop();
        }
        string result="";
        for(int i=0;i<n;i++){
            if(removeIndex.find(i)==removeIndex.end()){
                result.push_back(s[i]);
            }
        }
        return result;
    }
};