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
    void reorderList(ListNode* head) {
        ListNode* mid = head;

        if(mid == NULL || mid->next == NULL || mid->next->next == NULL)
            return;
        ListNode* fast = head->next;
        while(fast && fast->next){
            mid = mid->next;
            fast = fast->next->next;
        }

        ListNode* temp2 = mid->next;
        mid->next = NULL;
        
        // reverse the second half
        ListNode* prev = NULL;
        while(temp2) {
            ListNode* nxt = temp2->next;
            temp2->next = prev;
            prev = temp2;
            temp2 = nxt;
        }

        temp2 = prev;

        ListNode* temp1 = head;
        ListNode* curr = new ListNode();

        while(temp1 && temp2) {
            curr->next = temp1;
            temp1=temp1->next;
            curr = curr->next;
            curr->next = temp2;
            temp2 = temp2->next;
            curr = curr->next;
        }

        if(temp1) {
            curr->next = temp1;
        }

        return;
    }
};
