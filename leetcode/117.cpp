#include "../leet.h"

class Solution {
public:
  std::vector<Node *> levels;
  Node *connect(Node *root) {
    connect(root, 0);
    return root;
  }
  void connect(Node *root, int level) {
    if (!root) {
      return;
    }
    if (level + 1 > levels.size()) {
      levels.push_back(root);
    } else {
      levels[level]->next = root;
      levels[level] = root;
    }
    connect(root->left, level + 1);
    connect(root->right, level + 1);
  }
};
