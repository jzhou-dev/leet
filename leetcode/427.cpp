#include <vector>
class Node {
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight,
       Node *_bottomLeft, Node *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};
class Solution {
public:
  Node *construct(std::vector<std::vector<int>> &grid) {
    return construct(grid, {0, 0}, grid.size());
  }
  Node *construct(std::vector<std::vector<int>> &grid, std::pair<int, int> tl,
                  int len) {
    if (len == 1) {
      return new Node(grid[tl.first][tl.second], true);
    }
    Node *topLeft = construct(grid, tl, len / 2);
    Node *topRight = construct(grid, {tl.first, tl.second + len / 2}, len / 2);
    Node *bottomLeft =
        construct(grid, {tl.first + len / 2, tl.second}, len / 2);
    Node *bottomRight =
        construct(grid, {tl.first + len / 2, tl.second + len / 2}, len / 2);
    if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf &&
        bottomRight->isLeaf && topLeft->val == topRight->val &&
        topRight->val == bottomLeft->val &&
        bottomLeft->val == bottomRight->val) {
      return new Node(topLeft->val, true);
    } else {
      return new Node(topLeft->val, false, topLeft, topRight, bottomLeft,
                      bottomRight);
    }
  }
};
