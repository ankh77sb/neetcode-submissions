class Solution {
public:
    int dfs(vector<vector<int>>& dp, int i, int j) {
        if(i == dp.size() || j == dp[0].size()) return 0;
        if(dp[i][j]) return dp[i][j];
        dp[i][j] = dfs(dp, i+1, j) + dfs(dp, i, j+1);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[m-1][n-1] = 1;

        return dfs(dp, 0, 0);
    }
};
