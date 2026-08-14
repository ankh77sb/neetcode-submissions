class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        int l = 0, r = 0;
        int maxfreq = 0;
        int res = 0;
        vector<int> frqmap(26,0);

        while(r < n) {
            frqmap[s[r] - 'A']++;
            maxfreq = max(maxfreq, frqmap[s[r] - 'A']);

            while(r - l + 1 - maxfreq > k) {
                frqmap[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l + 1); 
            r++;
        }

        return res;
    }
};
