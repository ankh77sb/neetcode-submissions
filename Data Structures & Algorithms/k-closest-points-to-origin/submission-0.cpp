class Solution {
struct ComparePairs {
    bool operator()(const pair<double, vector<int>>& a, const pair<double, vector<int>>& b) {
        // Note: priority_queue is a max-heap by default. 
        // Returning 'first < first' makes it a max-heap (largest element on top).
        return a.first < b.first; 
    }
};

// Cleaner declaration
priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, ComparePairs> pq;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(int i = 0; i < points.size(); i++) {
            double d = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            // cout<<d<<endl;
            pq.push({d, points[i]});
        }

        while(pq.size() > k) {
            // cout<<pq.top().first<<endl;
            pq.pop();
        }
        vector<vector<int>> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
