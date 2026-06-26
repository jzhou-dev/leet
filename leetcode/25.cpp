#include "../leet.h"

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *result = nullptr;
    ListNode *last = nullptr;
    while (curr) {
      int i = 0;
      ListNode *temp_last = curr;
      ListNode *temp_curr = curr;
      while (i < k && temp_curr) {
        temp_curr = temp_curr->next;
        i++;
      }
      if (i != k) {
        prev = curr;
        curr = nullptr;
      }
      i = 0;
      while (i < k && curr) {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        i++;
      }
      if (last) {
        last->next = prev;
      }
      last = temp_last;
      if (!result) {
        result = prev;
      }
      prev = nullptr;
    }
    return result;
  }
};
