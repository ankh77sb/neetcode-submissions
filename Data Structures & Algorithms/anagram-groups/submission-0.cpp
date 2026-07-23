class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int m = strs.size();
        map<vector<int>,vector<string>> mp;

        for(int i = 0 ; i < m; i++) {
            vector<int> char_map(26,0);
            for(int j = 0 ; j < strs[i].size(); j++) {
                char_map[strs[i][j]-'a']++;
            }

            mp[char_map].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for(auto const& [key, val] : mp) {
            ans.push_back(val);
        }

        return ans;
        
    }
};