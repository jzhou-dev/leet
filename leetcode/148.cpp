#include "../leet.h"

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    if (prev) {
      prev->next = nullptr;
    }
    ListNode *left = sortList(head);
    ListNode *right = sortList(slow);
    return mergeSort(left, right);
  }
  ListNode *mergeSort(ListNode *l1, ListNode *l2) {
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
