class Solution {
public:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, bool> visited;
    string result;

    bool dfs(char ch) {
        if(visited.find(ch) != visited.end())
            return visited[ch];

        visited[ch] = true;
        for(char next: adj[ch]) {
            if(dfs(next)) {
                return true;
            }
        }
        visited[ch] = false;
        result.push_back(ch);
        return false;
    }

    string foreignDictionary(vector<string>& words) {
        
        for(const auto& word: words) {
            for(char ch: word) {
                adj[ch];
            }
        }

        for(int i = 0 ; i < words.size() - 1; i++) {
            string& w1 = words[i];
            string& w2 = words[i+1];

            size_t minLen = min(w1.length(), w2.length());

            if(w1.length() > w2.length() && w1.substr(0, w2.length()) == w2.substr(0, w2.length()))
                return "";
            
            for(size_t j = 0; j < minLen; j++) {
                if(w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        for(const auto& pair: adj) {
            if(dfs(pair.first)) {
                return "";
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
