class Solution {
    int findParent(vector<int>& parent, int x) {
        if(x == parent[x]) return x;
        return parent[x] = findParent(parent, parent[x]);
    }
    void unite(vector<int>& parent, int x, int y) {
        int parentx = findParent(parent,x);
        int parenty = findParent(parent,y);

        if(parentx == parenty) return;
        if(parentx < parenty) {
            parent[parenty] = parentx;
        } else parent[parentx] = parenty;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, int>> edges;
        int n = points.size();
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                edges.push_back(
                    make_pair(
                        abs(points[i][0] - points[j][0]) +                 
                        abs(points[i][1] - points[j][1]),
                        i * n + j
                    )
                );
            }
        }
        sort(edges.begin(), edges.end());
        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        
        int minCost = 0;
        for(int idx = 0; idx < edges.size(); idx++) {
            int e = edges[idx].first;
            int i = edges[idx].second / n;
            int j = edges[idx].second % n;
            int parentx = findParent(parent, i);
            int parenty = findParent(parent, j);

            if(parentx == parenty) {
                continue;
            } else {
                unite(parent, parentx, parenty);
                minCost += e;
            }
        }

        return minCost;
    }
};
