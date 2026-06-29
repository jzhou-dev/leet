#include "../leet.h"

class Solution {
public:
  void flatten(TreeNode *root) {
    while (root) {
      if (root->left) {
        TreeNode *trav = root->left;
        while (trav->right) {
          trav = trav->right;
        }
        trav->right = root->right;
        root->right = root->left;
        root->left = nullptr;
      }
      root = root->right;
    }
  }
};
