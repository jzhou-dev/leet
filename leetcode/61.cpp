#include "../leet.h"

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    ListNode *curr = head;
    int len = 0;
    while (curr) {
      curr = curr->next;
      len++;
    }
    if (len == 0) {
      k = 0;
    } else {
      k = k % len;
    }
    for (int i = 0; i < k; i++) {
      curr = head;
      int prev = curr->val;
      while (curr) {
        curr = curr->next;
        if (curr) {
          int temp = curr->val;
          curr->val = prev;
          prev = temp;
        } else {
          head->val = prev;
        }
      }
    }
    return head;
  }
};
