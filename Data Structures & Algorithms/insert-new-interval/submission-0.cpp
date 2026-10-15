class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        if(n == 0) {
            res.push_back(newInterval);
            return res;
        }

        int start = newInterval[0];
        int end = newInterval[1];
        int i = 0;
        for(; i < n; i++) {
            if(start <= intervals[i][1] && end >= intervals[i][0]) {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            } else if(end < intervals[i][0]) {
                res.push_back({start, end});
                break;
            } else {
                res.push_back(intervals[i]);   
            }
        }

        if(i == n) {
            res.push_back({start, end});
        } else {
            for(; i < n; i++)
                res.push_back(intervals[i]);
        }

        return res;
    }
};
