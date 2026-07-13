#include "../leet.h"

class Solution {
public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    if (lists.empty())
      return nullptr;
    return mergeKLists(lists, 0, lists.size() - 1);
  }
  ListNode *mergeKLists(std::vector<ListNode *> &lists, int start, int end) {
    if (start >= end) {
      return lists[start];
    }
    int mid = start + (end - start) / 2;
    ListNode *left = mergeKLists(lists, start, mid);
    ListNode *right = mergeKLists(lists, mid + 1, end);
    ListNode *dummy = new ListNode();
    ListNode *curr = dummy;
    while (left && right) {
      if (left->val < right->val) {
        curr->next = left;
        left = left->next;
      } else {
        curr->next = right;
        right = right->next;
      }
      curr = curr->next;
    }
    if (left) {
      curr->next = left;
    } else if (right) {
      curr->next = right;
    }
    return dummy->next;
  }
};
