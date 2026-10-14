class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text2.size(), 0);

        for(int i = 0; i < text1.size(); i++) {
            int prev = 0;
            for(int j = 0; j < text2.size(); j++) {
                int temp = dp[j];
                if(text1[i] == text2[j])
                    dp[j] = 1 + ((i > 0 & j > 0) ? prev: 0);
                else{
                    dp[j] = max(dp[j],(j? dp[j-1]: 0));
                }
                prev = temp;
            }
        }

        return dp[text2.size()-1];
    }
};
