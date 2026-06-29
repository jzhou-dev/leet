#include "../leet.h"

class Solution {
public:
  int sumNumbers(TreeNode *root) { return sumNumber(root, 0); }
  int sumNumber(TreeNode *root, int sum) {
    if (!root) {
      return 0;
    }
    sum = sum * 10 + root->val;
    if (!root->left && !root->right) {
      return sum;
    }
    return sumNumber(root->left, sum) + sumNumber(root->right, sum);
  }
};
