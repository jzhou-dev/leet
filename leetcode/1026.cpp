#include <algorithm>
class Solution {
public:
  int maxAncestorDiff(TreeNode *root) {
    int result = -1;
    maxAncestorDiff(root, result, INT_MAX, INT_MIN);
    return result;
  }
  void maxAncestorDiff(TreeNode *root, int &result, int min_val, int max_val) {
    if (!root) {
      return;
    }
    min_val = min(min_val, root->val);
    max_val = max(max_val, root->val);
    result = max(
        {result, std::abs(root->val - min_val), std::abs(root->val - max_val)});
    maxAncestorDiff(root->left, result, min_val, max_val);
    maxAncestorDiff(root->right, result, min_val, max_val);
  }
};
