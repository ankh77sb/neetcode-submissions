class Solution {
    vector<int> dp;
public:
    bool dfs(string& s, vector<string>& wordDict, int i) {
        if(dp[i] != -1) return dp[i];

        for(const string& w: wordDict) {
            if(i + w.length() <= s.length() && s.substr(i, w.length()) == w) {
                if(dfs(s, wordDict, i + w.length())) {
                    dp[i] = 1;
                    return true;
                }
            }
        }
        dp[i] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp = vector<int>(s.size() + 1, -1);
        dp[s.size()] = 1;
        return dfs(s, wordDict, 0);
    }
};
