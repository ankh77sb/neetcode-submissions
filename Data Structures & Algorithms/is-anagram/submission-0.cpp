class Solution {
public:
    bool isAnagram(string s, string t) {

        int n = s.size();
        int m = t.size();

        if(n != m) return false;
        
        vector<int> char_map(26,0);

        for(int i = 0; i < n; i++) {
            char_map[s[i]-'a']++;
            char_map[t[i]-'a']--;
        }

        for(int i = 0; i < 26; i++) {
            if(char_map[i])
                return false;
        }

        return true;
        
    }
};
