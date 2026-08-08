class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int n = heights.size();
        int res = 0;

        int i = 0;
        int  j = n - 1;

        while(i<j) {
            res = max((j - i) * min(heights[i], heights[j]), res);

            if(heights[i] < heights[j]) {
                i++;
            } else j--;
        }

        return res;
        
    }
};
