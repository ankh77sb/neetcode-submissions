class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited) {
        if(visited[i]) return;
        visited[i] = true;
        for(auto child: adj[i]) {
            dfs(child, adj, visited);
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for(int i = 0 ; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n, false);
        int ans = 0;
        for(int i = 0 ; i < n; i++) {
            if(visited[i]) continue;
            ans++;
            dfs(i, adj, visited);
        }
        
        return ans;
    }
};
