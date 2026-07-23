class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = "";

        unsigned long min_size = INT_MAX;
        int n = strs.size();

        for(int i = 0; i < n; i++) {
            min_size = min(min_size, strs[i].size());
        }
        bool exit = false;
        for(int j = 0; j < min_size; j++) {
            char curr = strs[0][j];
            for(int i = 1; i < n ; i++) {
                if(strs[i][j] != curr) {
                    exit = true;
                    break; 
                }
            }

            if(exit) break;
            ans += curr;
        }

        return ans;
        
    }
};