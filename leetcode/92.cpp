#include "../leet.h"

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    int i = 1;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *begin = nullptr;
    ListNode *end = nullptr;
    while (i <= right) {
      if (i == left - 1) {
        begin = curr;
      }
      if (i == left) {
        end = curr;
      }
      if (i > left) {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
      } else {
        prev = curr;
        curr = curr->next;
      }
      i++;
    }
    if (begin) {
      begin->next = prev;
    }
    if (end) {
      end->next = curr;
    }
    return head;
  }
};
