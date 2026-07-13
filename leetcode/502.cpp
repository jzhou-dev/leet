#include "../leet.h"

class Solution {
public:
  int findMaximizedCapital(int k, int w, std::vector<int> &profits,
                           std::vector<int> &capital) {
    std::vector<std::pair<int, int>> projects(profits.size());
    for (int i = 0; i < profits.size(); ++i) {
      projects[i] = {capital[i], profits[i]};
    }
    std::sort(projects.begin(), projects.end());
    std::priority_queue<int> pq;
    int j = 0;
    for (int i = 0; i < k; ++i) {
      while (j < projects.size() && projects[j].first <= w) {
        pq.push(projects[j++].second);
      }
      if (pq.empty()) {
        break;
      }
      w += pq.top();
      pq.pop();
    }
    return w;
  }
};
