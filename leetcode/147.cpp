#include <vector>
using namespace std;

class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    ListNode *dummy(0);
    ListNode *curr = head;
    dummy->next = head;
    while (curr && curr->next) {
      if (curr->next->val >= curr->val) {
        curr = curr->next;
      } else {
        ListNode *next = curr->next;
        curr->next = next->next;
        ListNode *prev = dummy;
        while (prev->next->val <= next->val) {
          prev = prev->next;
        }
        next->next = prev->next;
        prev->next = next;
      }
    }
    return dummy->next;
  }
};
