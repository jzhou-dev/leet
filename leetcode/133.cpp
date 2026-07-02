#include "../leet.h"

class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (!node) {
      return nullptr;
    }
    std::unordered_map<int, Node *> nodes;
    std::queue<Node *> queue;
    queue.push(node);
    nodes[node->val] = new Node(node->val);
    while (!queue.empty()) {
      Node *curr = queue.front();
      queue.pop();
      Node *copy = nodes[curr->val];
      for (auto n : curr->neighbors) {
        if (!nodes.count(n->val)) {
          nodes[n->val] = new Node(n->val);
          queue.push(n);
        }
        copy->neighbors.push_back(nodes[n->val]);
      }
    }
    return nodes[node->val];
  }
};
