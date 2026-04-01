class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char>st;
        int n=word.size();
        int index=-1;
        for(int i=0;i<n;i++){
            st.push(word[i]);
            if(word[i] ==ch ){
                index=i;
                break;
            }

        }
        if(index == -1){
           return word;
        } 
        string ans="";
        while(!st.empty()){
            char front=st.top();
            st.pop();
            ans=ans+front;
        }
        for(int i=index+1;i<n;i++){
            ans=ans+word[i];
        }
        return ans;

    }
};