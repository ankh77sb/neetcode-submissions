/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    struct CompareInterval {
        bool operator()(const Interval& a, const Interval& b) {
            return a.end > b.end; // Change to > for a min-heap
        }
    };
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const        Interval& b) {
            return a.start < b.start;
        });

        unsigned long res = 0;

        // No need to pass an object to the constructor here
        priority_queue<Interval, vector<Interval>, CompareInterval> q;

        for(int i = 0; i < n; i++) {
            cout<<intervals[i].start<<" "<<intervals[i].end<<endl;
            if(!q.empty() && q.top().end <= intervals[i].start) {
                // cout<<"popped "<<q.top().start<<" "<<q.top().end<<endl;
                q.pop();    
            }
            q.push(intervals[i]);
            res = max(res, q.size());
        }
        
        return (int) res;
    }
};
