#include "../leet.h"

class Solution {
public:
  std::vector<int> findOrder(int numCourses,
                             std::vector<std::vector<int>> &prerequisites) {
    std::vector<std::vector<int>> adj(numCourses);
    std::vector<int> numReqs(numCourses);
    for (auto req : prerequisites) {
      adj[req[1]].push_back(req[0]);
      numReqs[req[0]]++;
    }
    std::queue<int> queue;
    std::vector<int> result;
    for (int i = 0; i < numReqs.size(); i++) {
      if (numReqs[i] == 0) {
        queue.push(i);
      }
    }
    while (!queue.empty()) {
      int course = queue.front();
      queue.pop();
      result.push_back(course);
      numCourses--;
      for (int i = 0; i < adj[course].size(); ++i) {
        numReqs[adj[course][i]]--;
        if (numReqs[adj[course][i]] == 0) {
          queue.push(adj[course][i]);
        }
      }
    }
    if (numCourses == 0) {
      return result;
    } else {
      return {};
    }
  }
};
