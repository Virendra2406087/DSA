#include <stack>
#include <cctype>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long result = 0, num = 0;
        int sign = 1;

        for (char ch : s) {
            if (ch == ' ') continue;

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } 
            else if (ch == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } 
            else if (ch == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } 
            else if (ch == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } 
            else if (ch == ')') {
                result += sign * num;
                num = 0;

                long long prevSign = st.top(); st.pop();
                long long prevResult = st.top(); st.pop();

                result = prevResult + prevSign * result;
            }
        }

        return (int)(result + sign * num);
    }
};