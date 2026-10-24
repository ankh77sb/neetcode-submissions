class Solution {
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
        if((i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 )
        || vis[i][j] ||  grid[i][j] == 0) return 0;

        vis[i][j] = true;
        return 1 + dfs(grid, vis, i + 1, j) 
                 + dfs(grid, vis, i - 1, j)
                 + dfs(grid, vis, i, j + 1)
                 + dfs(grid, vis, i, j - 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int res = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j]) {
                    res = max(res, dfs(grid, visited, i, j));
                }
            }
        }

        return res;
    }
};
