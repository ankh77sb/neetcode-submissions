class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();
        if(n == 0 || s[0] == '0') return 0;

        vector<int> dp(n+1, 0);
        dp[0] = 1;

        for(int i = 1; i <= n; i++) {
            if(i >= 2 && s[i-2] != '0' &&
               stoi(s.substr(i-2, 2)) <= 26) {
                dp[i] += dp[i-2];
            }

            if(s[i-1] != '0')
                dp[i] += dp[i-1];
        }

        return dp[n];
    }
};