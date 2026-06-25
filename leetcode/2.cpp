#include "../leet.h"

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode *result = new ListNode();
    ListNode *curr = result;
    while (l1 || l2 || carry) {
      int sum = 0;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      if (carry != 0) {
        sum += carry;
        carry = 0;
      }
      curr->next = new ListNode(sum % 10);
      curr = curr->next;
      carry = sum / 10;
    }
    return result->next;
  }
};
