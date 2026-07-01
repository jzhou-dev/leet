#include "../leet.h"

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    TreeNode *prev = nullptr;
    return isValidBST(root, prev);
  }
  bool isValidBST(TreeNode *root, TreeNode *&prev) {
    if (!root) {
      return true;
    }
    bool left = isValidBST(root->left, prev);
    if (prev && prev->val >= root->val) {
      return false;
    }
    prev = root;
    bool right = isValidBST(root->right, prev);
    return left && right;
  }
};
