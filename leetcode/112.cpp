#include "../leet.h"

class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    return hasPathSum(root, targetSum, 0);
  }
  bool hasPathSum(TreeNode *root, int targetSum, int currSum) {
    if (!root) {
      return false;
    }
    currSum += root->val;
    if (!root->left && !root->right && currSum == targetSum) {
      return true;
    }
    return hasPathSum(root->left, targetSum, currSum) ||
           hasPathSum(root->right, targetSum, currSum);
  }
};
