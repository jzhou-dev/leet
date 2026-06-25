#include "../leet.h"

class Solution {
public:
  Node *copyRandomList(Node *head) {
    std::unordered_map<Node *, Node *> store;
    Node *copyHead = new Node(0);
    Node *curr = copyHead;
    Node *temp = head;
    while (head) {
      if (store.count(head)) {
        curr->next = store[head];
      } else {
        curr->next = new Node(head->val);
        store.insert({head, curr->next});
      }
      curr = curr->next;
      if (head->random) {
        if (store.count(head->random)) {
          curr->random = store[head->random];
        } else {
          curr->random = new Node(head->random->val);
          store.insert({head->random, curr->random});
        }
      }
      head = head->next;
    }
    for (auto i : store) {
      std::cout << i.first << " " << i.second << "\n";
    }
    return copyHead->next;
  }
};
