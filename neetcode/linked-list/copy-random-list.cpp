#include "leet.h"

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node* newHead = &dummy;
        unordered_map<Node*, Node*> nodes;
        Node* curr = head;
        Node* curr2 = newHead;
        while (curr) {
            Node* newNode = new Node(curr->val);
            nodes.insert({curr, newNode});
            curr2->next = newNode;
            curr = curr->next;
            curr2 = curr2->next;      
        }
        newHead = newHead->next;
        curr = head;
        curr2 = newHead;
        while (curr && curr2) {
            curr2->random = nodes[curr->random];
            curr = curr->next;
            curr2 = curr2->next;
        }
        return newHead;
    }
};