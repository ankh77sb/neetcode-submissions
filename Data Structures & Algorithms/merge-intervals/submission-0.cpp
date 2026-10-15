class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            if(start <= intervals[i][1] && end >= intervals[i][0]) {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            } else if(end < intervals[i][0]) {
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        res.push_back({start, end});
        return res;        
    }
};
