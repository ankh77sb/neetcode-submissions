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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummyHead = new ListNode(0, head);
        ListNode* temp = head;
        int total = 0;
        while(temp) {
            total++;
            temp=temp->next;
        }
        
        n = total - n + 1;
        temp = dummyHead;
        while(--n) {
            temp = temp->next;
        }

        if(temp && temp->next) {
            temp->next = temp->next->next;
        }

        return dummyHead->next;
    }
};
