#include "../leet.h"

class Solution {
public:
  bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::vector<std::vector<int>> adj(numCourses);
    std::vector<int> courseReqs(numCourses);
    for (int i = 0; i < prerequisites.size(); ++i) {
      adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
      courseReqs[prerequisites[i][0]]++;
    }
    std::queue<int> queue;
    for (int i = 0; i < numCourses; i++) {
      if (courseReqs[i] == 0) {
        queue.push(i);
      }
    }
    while (!queue.empty()) {
      int course = queue.front();
      queue.pop();
      numCourses--;
      for (int i = 0; i < adj[course].size(); i++) {
        courseReqs[adj[course][i]]--;
        if (courseReqs[adj[course][i]] == 0) {
          queue.push(adj[course][i]);
        }
      }
    }
    return true;
  }
};
