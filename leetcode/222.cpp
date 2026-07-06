#include "../leet.h"

class Solution {
public:
  int countNodes(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int left = getDepth(root->left);
    int right = getDepth(root->right);
    if (left == right) {
      return (1 << left) + countNodes(root->right);
    } else {
      return (1 << right) + countNodes(root->left);
    }
  }
  int getDepth(TreeNode *root) {
    int depth = 0;
    while (root) {
      depth++;
      root = root->left;
    }
    return depth;
  }
};
