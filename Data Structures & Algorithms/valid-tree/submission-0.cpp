class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        if(visited[node]) return false;

        visited[node] = true;

        for(auto child: adj[node]) {
            if(child == parent) continue;
            if(!dfs(child, node, adj, visited)) return false;
        }

        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        
        int m = edges.size();
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);

        for(int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
       
        if(!dfs(0, -1, adj, visited)) return false;
        
        for(int i = 0; i < n; i++) {
            if(visited[i] == false) return false;
        }

        return true;
    }
};
