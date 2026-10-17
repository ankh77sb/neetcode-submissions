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
    ListNode* reverseCurrK(ListNode* head, int k) {
        int x = k;
        ListNode* afterk = head;
        while(afterk && x) {
            afterk = afterk->next;
            x--;
        }
        if(afterk == NULL && x != 0) return head;

        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* prev = dummyHead;
        ListNode* curr = head;
        x = k;
        while(x-- && curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head->next = reverseCurrK(afterk, k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        return reverseCurrK(head, k);
    }
};
