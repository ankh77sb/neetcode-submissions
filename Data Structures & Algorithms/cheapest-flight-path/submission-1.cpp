class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> v(n);

        for(auto& f : flights) {
            v[f[0]].push_back({f[2], f[1]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        // {cost, node, flightsUsed}
        pq.push({0, src, 0});
        dist[src][0] = 0;

        while(!pq.empty()) {
            auto [d, node, stops] = pq.top();
            pq.pop();

            if(d > dist[node][stops]) continue;

            if(node == dst) return d;

            // At most k stops means at most k+1 flights
            if(stops == k + 1) continue;

            for(auto& child : v[node]) {
                int childDist = d + child.first;
                int nextNode = child.second;
                int childStop = stops + 1;

                if(childDist < dist[nextNode][childStop]) {
                    dist[nextNode][childStop] = childDist;
                    pq.push({childDist, nextNode, childStop});
                }
            }
        }

        return -1;
    }
};