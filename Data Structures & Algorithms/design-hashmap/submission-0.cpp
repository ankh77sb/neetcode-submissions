class MyHashMap {
private:
    struct ListNode {
        int key;
        int val;
        ListNode* next;
        ListNode(int key = -1, int val = -1, ListNode* next = nullptr)
            : key(key), val(val), next(next) {}
    };

    vector<ListNode*> map;

    int hash(int key) {
        return key % map.size();
    }

public:
    MyHashMap() {
        map.resize(1000);
        for(auto& m : map) {
            m = new ListNode();
        }
    }
    
    void put(int key, int value) {
        ListNode* temp = map[hash(key)];
        while(temp->next != nullptr) {
            if (temp->next->key == key) {
                temp->next->val = value;
                return;
            }
            temp = temp->next;
        }

        temp->next = new ListNode(key, value);
        return;
    }
    
    int get(int key) {
        ListNode* temp = map[hash(key)];
        while(temp->next != nullptr) {
            if (temp->next->key == key) {
                return temp->next->val;
            }
            temp = temp->next;
        }

        return -1;
    }
    
    void remove(int key) {

        ListNode* temp = map[hash(key)];
        while(temp->next != nullptr) {
            if (temp->next->key == key) {
                ListNode* rem = temp->next;
                temp->next = temp->next->next;
                delete rem;
                return;
            }
            temp = temp->next;
        }

        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */