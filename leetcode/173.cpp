#include "../leet.h"

class BSTIterator {
public:
  std::stack<TreeNode *> stack;
  BSTIterator(TreeNode *root) { pushLeftNodes(root); }
  int next() {
    TreeNode *temp = stack.top();
    stack.pop();
    pushLeftNodes(temp->right);
    return temp->val;
  }
  bool hasNext() { return !stack.empty(); }
  void pushLeftNodes(TreeNode *root) {
    if (!root) {
      return;
    }
    stack.push(root);
    pushLeftNodes(root->left);
  }
};
