#include "../leet.h"

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;
    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }
    while (fast) {
      fast = fast->next;
      prev = slow;
      slow = slow->next;
    }
    if (prev) {
      prev->next = slow->next;
    } else {
      head = head->next;
    }
    return head;
  }
};
