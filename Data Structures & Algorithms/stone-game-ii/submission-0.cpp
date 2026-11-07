class Solution {
public:
    int pickPiles(vector<vector<vector<int>>>&dp, vector<int>& piles,int n, int i, int m, int alice)
    {
        if(i >= n) return 0;
        if(dp[alice][i][m]!=-1)
            return dp[alice][i][m];
        
        if(alice) dp[alice][i][m] = 0;
        else dp[alice][i][m] = INT_MAX;

        int sum = 0;
        for(int x = 1; x <= 2 * m; x++) {
            if (i + x > piles.size()) break;
            sum += piles[i+ x - 1];
            if(alice == 1)
                dp[alice][i][m] = max(dp[alice][i][m], sum + pickPiles(dp, piles, n, i + x, max(x, m), 0));
            else 
                dp[alice][i][m] = min(dp[alice][i][m], pickPiles(dp, piles, n, i + x, max(x, m), 1));
        }

        return dp[alice][i][m];
    }    
 int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return pickPiles(dp, piles, n, 0, 1, 1);
    }
};