class Solution {
public:
    bool validIdx(int i, int j, int m, int n) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,pair<int,int>>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    q.push(make_pair(0, make_pair(i, j)));
                    grid[i][j] = INT_MAX;
                }
            }
        }

        while(!q.empty()) {
            // cout<<"here"<<endl;
            pair<int, pair<int,int>> p = q.front();
            q.pop();
            int d = p.first;
            int i = p.second.first;
            int j = p.second.second;

            if(grid[i][j] != INT_MAX) continue;
            grid[i][j] = d;
            
            if(validIdx(i+1, j, m, n) && grid[i+1][j] == INT_MAX) {
                q.push(make_pair(d + 1, make_pair(i+1, j)));
            }

            if(validIdx(i-1, j, m, n) && grid[i-1][j] == INT_MAX) {
                q.push(make_pair(d + 1, make_pair(i-1, j)));
            }

            if(validIdx(i, j+1, m, n) && grid[i][j+1] == INT_MAX) {
                q.push(make_pair(d + 1, make_pair(i, j+1)));
            }

            if(validIdx(i, j-1, m, n) && grid[i][j-1] == INT_MAX) {
                q.push(make_pair(d + 1, make_pair(i, j-1)));
            }
        }
    }
};
