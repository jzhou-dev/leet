#include "../leet.h"

class Solution {
public:
  std::vector<int> findOrder(int numCourses,
                             std::vector<std::vector<int>> &prerequisites) {
    std::vector<std::vector<int>> adj(numCourses);
    std::vector<int> numReqs(numCourses);
    for (auto prereq : prerequisites) {
      adj[prereq[1]].push_back(prereq[0]);
      numReqs[prereq[0]]++;
    }
    std::queue<int> q;
    std::vector<int> result;
    for (int i = 0; i < numReqs.size(); ++i) {
      if (numReqs[i] == 0) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int course = q.front();
      q.pop();
      numCourses--;
      result.push_back(course);
      for (auto i : adj[course]) {
        if (--numReqs[i] == 0) {
          q.push(i);
        }
      }
    }
    if (numCourses != 0) {
      return {};
    }
    return result;
  }
};
