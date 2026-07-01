#include "../leet.h"

class Solution {
public:
  int getMinimumDifference(TreeNode *root) {
    int result = INT_MAX;
    TreeNode *prev = nullptr;
    getMinimumDifference(root, prev, result);
    return result;
  }
  void getMinimumDifference(TreeNode *root, TreeNode *&prev, int &result) {
    if (!root) {
      return;
    }
    if (root->left) {
      getMinimumDifference(root->left, prev, result);
    }
    if (prev) {
      result = std::min(result, std::abs(prev->val - root->val));
    }
    prev = root;
    if (root->right) {
      getMinimumDifference(root->right, prev, result);
    }
  }
};
