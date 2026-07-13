#include "../leet.h"

class Solution {
public:
  std::vector<int>
  findRedundantConnection(std::vector<std::vector<int>> &edges) {
    std::unordered_map<int, int> parents;
    for (int i = 0; i <= edges.size(); ++i) {
      parents[i] = i;
    }
    for (int i = 0; i < edges.size(); ++i) {
      if (!createUnion(edges[i][0], edges[i][1], parents))
        return edges[i];
    }
    return {};
  }

private:
  int find(int node, std::unordered_map<int, int> &parents) {
    return parents[node] == node ? node : find(parents[node], parents);
  }
  bool createUnion(int start, int end, std::unordered_map<int, int> &parents) {
    int start_root = find(start, parents);
    int end_root = find(end, parents);
    if (start_root == end_root)
      return false;
    parents[end_root] = start_root;
    return true;
  }
};
