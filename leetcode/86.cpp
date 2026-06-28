#include "../leet.h"

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    std::vector<int> less;
    std::vector<int> greater;
    ListNode *curr = head;
    while (curr) {
      if (curr->val < x) {
        less.push_back(curr->val);
      } else {
        greater.push_back(curr->val);
      }
      curr = curr->next;
    }
    curr = head;
    for (auto num : less) {
      curr->val = num;
      curr = curr->next;
    }
    for (auto num : greater) {
      curr->val = num;
      curr = curr->next;
    }
    return head;
  }
};
