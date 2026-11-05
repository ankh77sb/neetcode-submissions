class Solution {
public:
    int borders(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return 1;
        if(grid[i][j] == -1) return 0;
        grid[i][j] = -1;

        int directions[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int res = 0;
        for(int k = 0; k < 4; k++) {
            res += borders(grid, i + directions[k][0], j + directions[k][1], m, n);
        }

        return res;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    return borders(grid, i, j, m, n);
                }
            }
        }
        return 0;
    } 
};