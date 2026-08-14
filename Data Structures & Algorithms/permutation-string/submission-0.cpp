class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);

        int n = s1.size();
        int m = s2.size();

        if(n > m) return false;

        for(int i = 0; i < n; i++) {
            mp1[s1[i] - 'a']++;
            mp2[s2[i] - 'a']++;
        }

        int matches = 0;
        for(int i = 0; i < 26; i++) {
            if(mp1[i] == mp2[i]) matches++;
        }

        int l = 0;
        for(int r = n; r < m; r++) {
            if(matches == 26) return true;
            
            int idx = s2[r] - 'a';
            mp2[idx]++;
            if(mp2[idx] == mp1[idx]) matches++;
            else if(mp2[idx] == mp1[idx] + 1) matches--;

            idx = s2[l] - 'a';
            mp2[idx]--;
            if(mp2[idx] == mp1[idx]) matches++;
            else if(mp2[idx] == mp1[idx] - 1) matches--;
            l++;
        }

        return matches == 26;
        
    }
};
