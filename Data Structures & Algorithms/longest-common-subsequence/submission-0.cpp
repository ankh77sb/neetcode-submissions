class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));

        for(int i = 0; i < text1.size(); i++) {
            for(int j = 0; j < text2.size(); j++) {
                if(text1[i] == text2[j])
                    dp[i][j] = 1 + ((i > 0 & j > 0) ? dp[i-1][j-1]: 0);
                else{
                    dp[i][j] = max((i ? dp[i-1][j]: 0),(j? dp[i][j-1]: 0));
                }
            }
        }

        return dp[text1.size()-1][text2.size()-1];
    }
};
