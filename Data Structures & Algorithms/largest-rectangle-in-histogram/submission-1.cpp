class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>> st;
        int maxArea = 0;

        for(int i = 0 ; i < n; i++) {
            int startIndex = i;
            while(!st.empty() && st.top().second > heights[i])      
            {
                pair<int,int> curr = st.top();
                st.pop();
                maxArea = max(maxArea, (i - curr.first)*curr.second);
                startIndex = curr.first;
            }
            st.push({startIndex, heights[i]});
        }

        while(!st.empty()) {
            maxArea = max(maxArea, (n - st.top().first) * st.top().second);
            st.pop();
        }

        return maxArea;


    }
};
