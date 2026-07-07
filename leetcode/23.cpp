#include "../leet.h"

class Solution {
public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    if (lists.empty()) {
      return nullptr;
    }
    return mergeKLists(lists, 0, lists.size() - 1);
  }
  ListNode *mergeKLists(std::vector<ListNode *> &lists, int start, int end) {
    if (start >= end) {
      return lists[start];
    }
    int mid = start + (end - start) / 2;
    ListNode *left = mergeKLists(lists, start, mid);
    ListNode *right = mergeKLists(lists, mid + 1, end);
    return merge(left, right);
  }
  ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    while (l1 || l2) {
      if (!l1) {
        curr->next = l2;
        break;
      }
      if (!l2) {
        curr->next = l1;
        break;
      }
      if (l1->val <= l2->val) {
        curr->next = l1;
        curr = curr->next;
        l1 = l1->next;
      } else {
        curr->next = l2;
        curr = curr->next;
        l2 = l2->next;
      }
    }
    return dummy->next;
  }
};
