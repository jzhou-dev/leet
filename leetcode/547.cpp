using namespace std;
#include <unordered_set>
#include <vector>

class Solution {
public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();
    vector<int> parents(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < parents.size(); ++i) {
      parents[i] = i;
    }
    for (int i = 0; i < isConnected.size(); ++i) {
      for (int j = 0; j < isConnected[i].size(); ++j) {
        if (isConnected[i][j]) {
          _union(parents, rank, i, j);
        }
      }
    }
    unordered_set<int> count;
    for (auto parent : parents) {
      count.insert(find(parents, parent));
    }
    return count.size();
  }
  void _union(vector<int> &parents, vector<int> &rank, int i, int j) {
    int pi = find(parents, i);
    int pj = find(parents, j);
    if (rank[j] < rank[i]) {
      swap(pi, pj);
      rank[pj]++;
    }
    if (pi != pj) {
      parents[pi] = pj;
    }
  }
  int find(vector<int> &parents, int i) {
    if (parents[i] != i) {
      parents[i] = find(parents, parents[i]);
    }
    return parents[i];
  }
};
