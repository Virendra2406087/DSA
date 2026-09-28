class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0;
        int maxi = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
                ans++;
                maxi = max(maxi, ans);
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                    ans--;
                }
            }
        }

        return maxi;
    }
};