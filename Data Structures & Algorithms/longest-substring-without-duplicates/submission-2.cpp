class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int r = 0;
        int l = 0;
        int res = 0;
        for(; r < n; r++) {
            mp[s[r]]++;
            while(mp[s[r]] > 1) {
                mp[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};
