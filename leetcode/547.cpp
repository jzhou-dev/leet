#include "../leet.h"

class Solution {
public:
  std::vector<int> parents;
  std::vector<int> rank;
  int findCircleNum(std::vector<std::vector<int>> &isConnected) {
    for (int i = 0; i < isConnected.size(); ++i) {
      parents.push_back(i);
      rank.push_back(0);
    }
    int result = 0;
    for (int i = 0; i < isConnected.size(); ++i) {
      for (int j = i; j < isConnected.size(); ++j) {
        if (isConnected[i][j]) {
          Union(i, j);
        }
      }
    }
    for (int i = 0; i < parents.size(); ++i) {
      if (i == parents[i])
        result++;
    }
    return result;
  }

private:
  int find(int root) {
    return root == parents[root] ? root : parents[root] = find(parents[root]);
  }
  void Union(int i, int j) {
    int pi = find(i);
    int pj = find(j);
    if (pi == pj)
      return;
    if (rank[pi] < rank[pj]) {
      std::swap(pi, pj);
    }
    parents[pj] = pi;
    if (rank[pi] == rank[pj]) {
      rank[pi]++;
    }
  }
};
