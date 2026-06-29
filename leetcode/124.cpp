#include "../leet.h"

class Solution {
public:
  int maxPathSum(TreeNode *root) {
    int result = root->val;
    maxPathSum(root, result);
    return result;
  }
  int maxPathSum(TreeNode *root, int &result) {
    if (!root) {
      return 0;
    }
    int left = std::max(0, maxPathSum(root->left, result));
    int right = std::max(0, maxPathSum(root->right, result));
    result = std::max(result, left + right + root->val);
    return std::max(left, right) + root->val;
  }
};
