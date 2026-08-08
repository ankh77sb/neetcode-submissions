class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        if(n < 3) return 0;
        vector<int> nextLarger(n, 0);
        vector<int> prevLarger(n, 0);
        
        int currmax = height[n-1];
     
        for(int i = n - 2 ; i>= 0; i--) {
            currmax = max(currmax, height[i]);
            nextLarger[i] = currmax;
        }
        currmax = height[0];

        for(int i = 1; i < n; i++) {
            currmax = max(currmax, height[i]);
            prevLarger[i] = currmax;
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += max(0, min(prevLarger[i], nextLarger[i]) - height[i]);
        }
        
        return res;
    }
};
