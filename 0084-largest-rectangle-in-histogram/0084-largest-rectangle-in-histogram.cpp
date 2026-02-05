class Solution {
public:
    void nextSmallerElement(vector<int>& heights, vector<int>& nextAns) {
        stack<int> st;
        st.push(-1);
        int n = heights.size();
        nextAns.resize(n);

        for (int i = n - 1; i >= 0; i--) {
            int element = heights[i];

            while (st.top() != -1 && heights[st.top()] >= element) {
                st.pop();
            }

            nextAns[i] = st.top();
            st.push(i);
        }
    }

    void prevSmallerElement(vector<int>& heights, vector<int>& prevAns) {
        stack<int> st;
        st.push(-1);
        int n = heights.size();
        prevAns.resize(n);

        for (int i = 0; i < n; i++) {
            int element = heights[i];

            while (st.top() != -1 && heights[st.top()] >= element) {
                st.pop();
            }

            prevAns[i] = st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> prevAns;
        vector<int> nextAns;

        nextSmallerElement(heights, nextAns);
        prevSmallerElement(heights, prevAns);

        for (int i = 0; i < nextAns.size(); i++) {
            if (nextAns[i] == -1) {
                nextAns[i] = nextAns.size();
            }
        }

        int maxArea = INT_MIN;

        for (int i = 0; i < nextAns.size(); i++) {
            int height = heights[i];
            int width = nextAns[i] - prevAns[i] - 1;
            int currArea = height * width;
            maxArea = max(maxArea, currArea);
        }

        return maxArea;
    }
};
