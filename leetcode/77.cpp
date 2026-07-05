#include "../leet.h"

class Solution {
public:
  std::vector<std::vector<int>> result;
  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<int> curr;
    combine(curr, n, 1, k);
    return result;
  }
  void combine(std::vector<int> &curr, int n, int index, int k) {
    if (curr.size() == k) {
      result.push_back(curr);
      return;
    }
    for (int i = index; i <= n; ++i) {
      curr.push_back(i);
      combine(curr, n, i + 1, k);
      curr.pop_back();
    }
  }
};
