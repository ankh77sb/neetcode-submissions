class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int res = 1;
        int l = 0;
        int r = 0;
        unordered_map<int, int> mp;

        if(n==0) return 0;

        while(r < n) {
            if(mp.find(s[r]) == mp.end() || mp[s[r]] == -1) {
                mp[s[r]] = r;
                r++;
                res = max(res, r - l);
            } else {
                if(mp[s[l]] == l) {
                    mp[s[l]] = -1;
                } l++;
            }
        }

        return res;

    }
};
