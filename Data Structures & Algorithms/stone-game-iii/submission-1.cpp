class Solution {
    vector<int> dp;
    vector<int> suffixSum;

public:
    int recur(vector<int>& stoneValue, int n, int i) {
        if(i >= n) return 0;
        if(dp[i]!=INT_MIN) return dp[i];
       
        for(int k = 0; k < 3; k++) {
            if(i + k + 1 <= n)
            dp[i] = max(dp[i], suffixSum[i] - recur(stoneValue, n, i + k + 1));
        }

        return dp[i];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.resize(n, INT_MIN);
        suffixSum.resize(n,0);
        suffixSum[n-1] = stoneValue[n-1];
        for(int i = n - 2; i >= 0; i--) {
            suffixSum[i] += (suffixSum[i+1] + stoneValue[i]);
        }
        // recur+memo
        dp[0] = recur(stoneValue, n, 0);
        cout<<dp[0]<<" "<<suffixSum[0]<<endl;
        if(suffixSum[0] - dp[0] < dp[0])
                return "Alice";
        else if(suffixSum[0] - dp[0] == dp[0])
                return "Tie";
        else return "Bob";
    }

};