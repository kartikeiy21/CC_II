class Solution {
public:
    vector<int> prevSmaller(vector<int>& h) {
        int n = h.size();
        vector<int> prev(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }
            if (st.empty()) {
                prev[i] = -1;
            } else {
                prev[i] = st.top();
            }
            st.push(i);
        }
        return prev;
    }
    vector<int> nextSmaller(vector<int>& h) {
        int n = h.size();
        vector<int> next(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }
            if (st.empty()) {
                next[i] = n;
            } else {
                next[i] = st.top();
            }
            st.push(i);
        }
        return next;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = prevSmaller(heights);
        vector<int> next = nextSmaller(heights);
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            int width = next[i] - prev[i] - 1;
            int area = heights[i] * width;
            ans = max(ans, area);
        }
        return ans;
    }
};