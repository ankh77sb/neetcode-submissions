/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == nullptr) return NULL;

        Node* curr = head;
        unordered_map<Node*, Node*> mp;

        while(curr) {
            if(mp.find(curr) == mp.end()) {
                mp[curr] = new Node(curr->val);
            }
            if(curr->next && mp.find(curr->next) == mp.end()) {
                mp[curr->next] = new Node(curr->next->val);
            }
            mp[curr]->next = mp[curr->next];
            if(curr->random && mp.find(curr->random) == mp.end()) {
                mp[curr->random] = new Node(curr->random->val);
            }
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }
        return mp[head];
    }
};
