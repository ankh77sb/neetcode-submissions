class MyHashSet {
public:
    vector<bool> st;

    MyHashSet() {
        st = vector<bool> (1000000, false);
    }
    
    void add(int key) {
        st[key] = true;
        return;
    }
    
    void remove(int key) {
        st[key] = false;
        return;
    }
    
    bool contains(int key) {
        return st[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */