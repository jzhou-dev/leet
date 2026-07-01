#include "../leet.h"

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    int result = 0;
    kthSmallest(root, result, k);
    return result;
  }
  void kthSmallest(TreeNode *root, int &result, int &k) {
    if (!root) {
      return;
    }
    kthSmallest(root->left, result, k);
    k--;
    if (k == 0) {
      result = root->val;
    }
    kthSmallest(root->right, result, k);
  }
};
