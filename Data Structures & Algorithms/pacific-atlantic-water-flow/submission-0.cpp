class Solution {
public:

    void dfs(int i, int j,
             vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             int parent) {

        int n = heights.size();
        int m = heights[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m)
            return;

        if(visited[i][j])
            return;

        // Reverse direction:
        // can only go to equal/higher cells
        if(heights[i][j] < parent)
            return;

        visited[i][j] = true;

        dfs(i + 1, j, heights, visited, heights[i][j]);
        dfs(i - 1, j, heights, visited, heights[i][j]);
        dfs(i, j + 1, heights, visited, heights[i][j]);
        dfs(i, j - 1, heights, visited, heights[i][j]);
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(
            n, vector<bool>(m, false)
        );

        vector<vector<bool>> atlantic(
            n, vector<bool>(m, false)
        );

        // LEFT and RIGHT boundaries
        for(int i = 0; i < n; i++) {

            // Pacific: left
            dfs(i, 0, heights, pacific, INT_MIN);

            // Atlantic: right
            dfs(i, m - 1, heights, atlantic, INT_MIN);
        }

        // TOP and BOTTOM boundaries
        for(int j = 0; j < m; j++) {

            // Pacific: top
            dfs(0, j, heights, pacific, INT_MIN);

            // Atlantic: bottom
            dfs(n - 1, j, heights, atlantic, INT_MIN);
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};