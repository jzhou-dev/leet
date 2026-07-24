#include "../leet.h"

class Solution {
public:
  bool isBipartite(std::vector<std::vector<int>> &graph) {
    int n = graph.size();
    std::vector<int> parents(n);
    std::vector<int> rank(n, 0);
    for (int i = 0; i < n; ++i) {
      parents[i] = i;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < graph[i].size(); ++j) {
        if (find(i, parents) == find(graph[i][j], parents))
          return false;
        Union(graph[i][0], graph[i][j], parents, rank);
      }
    }
    return true;
  }

private:
  void Union(int i, int j, std::vector<int> &parents, std::vector<int> &rank) {
    int pi = find(i, parents);
    int pj = find(j, parents);
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
  int find(int root, std::vector<int> &parents) {
    return parents[root] == root ? root : find(parents[root], parents);
  }
};
