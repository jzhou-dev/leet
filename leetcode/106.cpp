#include "../leet.h"

class Solution {
public:
  std::unordered_map<int, int> store;
  int index = 0;
  TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
    index = postorder.size() - 1;
    for (int i = 0; i < inorder.size(); ++i) {
      store[inorder[i]] = i;
    }
    return buildTree(inorder, postorder, 0, inorder.size() - 1);
  }
  TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder,
                      int left, int right) {
    if (left > right) {
      return nullptr;
    }
    int mid = store[postorder[index]];
    TreeNode *root = new TreeNode(postorder[index--]);
    root->right = buildTree(inorder, postorder, mid + 1, right);
    root->left = buildTree(inorder, postorder, left, mid - 1);
    return root;
  }
};
