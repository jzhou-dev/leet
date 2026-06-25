#include "../leet.h"

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode();
    ListNode *curr = dummy;
    while (list1 || list2) {
      if (!list1) {
        curr->next = list2;
        break;
      }
      if (!list2) {
        curr->next = list1;
        break;
      }

      if (list1->val < list2->val) {
        curr->next = new ListNode(list1->val);
        list1 = list1->next;
      } else {
        curr->next = new ListNode(list2->val);
        list2 = list2->next;
      }
      curr = curr->next;
    }
    return dummy->next;
  }
};
