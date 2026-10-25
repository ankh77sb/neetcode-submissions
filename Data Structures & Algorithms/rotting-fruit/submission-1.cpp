class Solution {
public:
    bool valIdx(int i, int j, int m, int n) {
        return (i >= 0 &&
                j >= 0 &&
                i < m  &&
                j < n);
    }
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int res = 0;
        queue<pair<int, pair<int, int>>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push(make_pair(0, make_pair(i, j)));  
                    grid[i][j] = 1; 
                }
            }
        }

        while(!q.empty()) {
            pair<int, pair<int, int>> p = q.front();
            q.pop();
            int d = p.first;
            int i = p.second.first;
            int j = p.second.second;

            if(grid[i][j] == 2) continue;
            res = max(res, d);
            grid[i][j] = 2;

            if(valIdx(i + 1, j, m, n) && grid[i+1][j] == 1) {
                q.push(make_pair(d+1, make_pair(i+1, j)));
            }

            if(valIdx(i - 1, j, m, n) && grid[i-1][j] == 1) {
                q.push(make_pair(d+1, make_pair(i-1, j)));
            }

            if(valIdx(i, j + 1, m, n) && grid[i][j+1] == 1) {
                q.push(make_pair(d+1, make_pair(i, j+1)));
            }

            if(valIdx(i, j - 1, m, n) && grid[i][j-1] == 1) {
                q.push(make_pair(d+1, make_pair(i, j-1)));
            }
        }

        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return res;
    }
};
