/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {

        if(head == NULL || head->next == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(slow && fast&& slow!=fast) {
            slow = slow->next;
            if(fast)
            fast = fast->next;
            if(fast)
            fast = fast->next;            
        }

        return slow == fast;
    }
};
