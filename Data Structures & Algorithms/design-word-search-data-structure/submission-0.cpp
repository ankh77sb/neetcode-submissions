class WordDictionary {
    struct Word {
        bool endOfWord;
        vector<Word*> v;
        Word() : v(26, nullptr), endOfWord(false) {}    
    };
    Word* root;
public:
    WordDictionary() {
        root = new Word();
    }
    
    void addWord(string word) {
        Word* curr = root;
        for(char c: word) {
            int idx = c - 'a';
            if(curr->v[idx] == nullptr) {
                curr->v[idx] = new Word();
            } 
            curr = curr->v[idx]; 
        }
        curr->endOfWord = true;
    }

    bool dfs(string& word, int j, Word* curr) {
        if(curr == nullptr) return false;
        if(j == word.size()) return curr->endOfWord;
        char c = word[j];
        if(c == '.') {
            for(int i = 0; i <  26; i++) {
                if(dfs(word, j + 1, curr->v[i]))
                    return true;
            }
            return false;
        }
        else { int idx = c - 'a';
            if(curr->v[idx] == nullptr) {
                return false;
            } 
            curr = curr->v[idx]; 
            return dfs(word, j + 1, curr);
        }  
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
