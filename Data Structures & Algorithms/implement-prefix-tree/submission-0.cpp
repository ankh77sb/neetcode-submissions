class PrefixTree {
    struct Node {
        bool endOfWord;
        vector<Node*> v;
        Node() {
            v = vector<Node*>(26, nullptr);
            endOfWord = false;
        }
    };
    Node* head;

public:
    PrefixTree() {
        head = new Node();
    }
    
    void insert(string words) {
        Node* curr = head;
        for(char c: words) {
            int idx = c - 'a';
            if(curr->v[idx] == nullptr) {
                curr->v[idx] = new Node();
            }
            curr = curr->v[idx];
        }
        curr->endOfWord = true;
    }
    
    bool search(string words) {
        Node* curr = head;
        for(char c: words) {
            int idx = c - 'a';
            if(curr->v[idx] == nullptr) {
                return false;
            }
            curr = curr->v[idx];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = head;
        for(char c: prefix) {
            int idx = c - 'a';
            if(curr->v[idx] == nullptr) {
                return false;
            }
            curr = curr->v[idx];
        }
        return true;
    }
};
