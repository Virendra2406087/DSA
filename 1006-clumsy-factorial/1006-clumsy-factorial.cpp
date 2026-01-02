class Solution {
public:
    int clumsy(int n) {
        stack<int>st;
        st.push(n);
        n--;
        int op=0;  // 0=*, 1=/, 2=+,3=-
        while(n>0){
            if(op==0){
                int top=st.top();
                st.pop();
                st.push(top*n);
            }
            else if(op==1){
                int top=st.top();
                st.pop();
                st.push(top/n);
            }
            else if(op==2){
                st.push(+n);
            }
            else{
                
                st.push(-n);
            }
            op = (op + 1) % 4;
               n--;
        }
        int result=0;
        while(!st.empty()){
            result=result+st.top();
            st.pop();
        }
        return result;

    }
};