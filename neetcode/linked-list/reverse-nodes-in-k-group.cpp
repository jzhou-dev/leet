#include "leet.h"

class Solution {
public:
    bool checkKNodes(ListNode* head, int k) {
        for (int i = 0; i < k; i++) {
            if (head) {
                head = head->next;
            } else {
                return false;
            }
        }
        return true;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prevCurr;
        int index = 0;
        while (true) {
            ListNode* tail = curr;
            ListNode* reverseCurr = curr;
            ListNode* prev = nullptr;
            if (!checkKNodes(curr, k)) {
                break;
            }
            for (int i = 0; i < k; i++) {
                ListNode* temp = reverseCurr->next;
                reverseCurr->next = prev;
                prev = reverseCurr;
                reverseCurr = temp;
            }

            if (index == 0) {
                head = prev;
            } else {
                prevCurr->next = prev;
            }
            prevCurr = curr;
            tail->next = reverseCurr;
            curr = reverseCurr;
            index++;
        }
        return head;
    }
};