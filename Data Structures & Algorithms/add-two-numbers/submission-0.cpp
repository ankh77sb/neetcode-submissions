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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummyHead = new ListNode();
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* curr = dummyHead;

        int carryOver = 0;
        while(temp1 && temp2) {
            int val = (carryOver + temp1->val + temp2->val)%10;
            carryOver = (carryOver + temp1->val + temp2->val)/10;
            curr->next = new ListNode(val);
            curr = curr->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1) {
            int val = (carryOver + temp1->val)%10;
            carryOver = (carryOver + temp1->val)/10;
            curr->next = new ListNode(val);
            curr = curr->next;
            temp1 = temp1->next;
        }

        while(temp2) {
            int val = (carryOver + temp2->val)%10;
            carryOver = (carryOver + temp2->val)/10;
            curr->next = new ListNode(val);
            curr = curr->next;
            temp2 = temp2->next;
        }

        while(carryOver) {
            int val = (carryOver)%10;
            carryOver = (carryOver)/10;
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        
        return dummyHead->next;
    }
};
