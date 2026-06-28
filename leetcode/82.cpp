#include "../leet.h"

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *curr = head;
    ListNode *prev = nullptr;
    while (curr) {
      ListNode *start = curr;
      while (start && start->val == curr->val) {
        start = start->next;
      }
      if (start != curr->next) {
        if (prev) {
          prev->next = start;
        } else {
          head = start;
        }
      } else {
        prev = curr;
      }
      curr = start;
    }
    return head;
  }
};
