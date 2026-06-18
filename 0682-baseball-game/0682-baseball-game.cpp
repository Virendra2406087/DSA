class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(int i=0;i<operations.size();i++){
            string ch=operations[i];
            if(ch=="+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.push(first);
                st.push(first + second);
            }else if(ch=="D"){
                int top = st.top();
                st.push(2 * top);
            }else if(ch=="C"){
                st.pop();
            }else{
                st.push(stoi(ch));
            }
        }
        int ans=0;
        while(! st.empty()){
            int val=st.top();
            st.pop();
            ans+=val;
        }
        return ans;
        
    }
};