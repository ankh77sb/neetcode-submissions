class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if(a[1] < b[1]) return true;
            if(a[1] > b[1]) return false;
            if(a[0] <= b[0]) return false;
            return true; 
        });

        int res = 0;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {
            if(start < intervals[i][1] && end > intervals[i][0]) {
                res++;
            } else {
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        return res;
    }
};
