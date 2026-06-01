#include "leet.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int index = 0;
        ListNode dummy(0);
        ListNode* head = &dummy;
        ListNode* curr = head;
        int total = 0;
        while (l1 || l2 || total != 0) {
            if (l1) {
                total += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                total += l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(total % 10);
            total = total / 10;
            curr = curr->next;
        }
        return head->next;
    }
};
