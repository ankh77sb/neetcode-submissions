class Solution {
public:
    int findParent(vector<int>& parent, int x) {
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent, parent[x]);
    }
    void unite(vector<int>& parent, int x, int y) {
        int parentX = findParent(parent, x);
        int parentY = findParent(parent, y);

        if(parentX != parentY) {
            if(parentX < parentY) {
                parent[parentX] = parentY;
            } else 
            parent[parentY] = parentX;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1); 
        for(int i = 0; i <= n; i++)
            parent[i] = i;

        vector<int> ans(2, -1);
        for(int i = 0; i < n; i++) {
            int x = findParent(parent, edges[i][0]);
            int y = findParent(parent, edges[i][1]);

            if(x == y){
                ans[0] = edges[i][0];
                ans[1] = edges[i][1];
            } else {
                unite(parent, x,y);
            }
        }

        return ans;
    }
};
