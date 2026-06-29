#include "../leet.h"

class Solution {
public:
  std::unordered_map<int, int> store;
  int index = 0;
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      store[inorder[i]] = i;
    }
    return buildTree(preorder, inorder, 0, inorder.size() - 1);
  }
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder,
                      int left, int right) {
    if (left > right) {
      return nullptr;
    }
    int mid = store[preorder[index]];
    TreeNode *root = new TreeNode(preorder[index++]);
    root->left = buildTree(preorder, inorder, left, mid - 1);
    root->right = buildTree(preorder, inorder, mid + 1, right);
    return root;
  }
};
