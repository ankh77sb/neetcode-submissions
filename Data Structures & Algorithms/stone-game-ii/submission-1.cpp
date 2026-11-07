class Solution {
    vector<int> suffixSum;
public:
    int pickPiles(vector<vector<int>>&dp, vector<int>& piles,int n, int i, int m)
    {
        if(i == n) return 0;
        if(dp[i][m]!=-1)
            return dp[i][m];
        dp[i][m] = 0;
        
        for(int x = 1; x <= 2 * m; x++) {
            if (i + x > piles.size()) break;
            dp[i][m] = max(dp[i][m], suffixSum[i] -  pickPiles(dp, piles, n, i + x, max(x, m)));
        }
        return dp[i][m];
    }    
 int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        suffixSum.resize(n);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = piles[i] + suffixSum[i + 1];
        }
        return pickPiles(dp, piles, n, 0, 1);
    }
};