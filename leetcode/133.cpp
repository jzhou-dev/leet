#include <queue>
#include <unordered_set>
#include <vector>

class Node {
public:
  int val;
  std::vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node *>();
  }
  Node(int _val, std::vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};
class Solution {
public:
  Node *cloneGraph(Node *node) {
    std::unordered_map<int, Node *> nodes;
    std::unordered_set<Node *> visited;
    std::queue<Node *> queue;
    if (node) {
      queue.push(node);
    }
    visited.insert(node);
    while (!queue.empty()) {
      Node *curr = queue.front();
      queue.pop();
      if (!nodes.count(curr->val)) {
        nodes[curr->val] = new Node(curr->val);
      }
      for (auto edge : curr->neighbors) {
        if (!visited.count(edge)) {
          queue.push(edge);
          visited.insert(edge);
        }
        if (!nodes.count(edge->val)) {
          nodes[edge->val] = new Node(edge->val);
        }
        nodes[curr->val]->neighbors.push_back(nodes[edge->val]);
      }
    }
    if (node) {
      return nodes[node->val];
    }
    return nullptr;
  }
};
