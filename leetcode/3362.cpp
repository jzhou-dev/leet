#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  int maxRemoval(vector<int> &nums, vector<vector<int>> &queries) {
    sort(queries.begin(), queries.end());
    vector<int> decrements(nums.size());
    set<vector<int>> combined_queries;
    set<vector<int>> regular_queries(queries.begin(), queries.end());
    for (auto query : queries) {
      for (int i = query.front(); i <= query.back(); ++i) {
        decrements[i]++;
      }
    }
    vector<int> curr = queries[0];
    for (int i = 1; i < queries.size(); ++i) {
      if (queries[i][0] > curr[1]) {
        combined_queries.insert(curr);
        curr = queries[i];
      } else {
        curr[1] = max(curr[1], queries[i][1]);
      }
    }
    combined_queries.insert(curr);
    curr = {0, 0};
    int result = 0;
    for (int i = 1; i <= decrements.size(); ++i) {
      if (decrements[i] <= nums[i] || i == decrements.size()) {
        if (combined_queries.count(curr) || regular_queries.count(curr)) {
          while (true) {
            for (int j = curr.front(); j <= curr.back(); ++j) {
              if (decrements[j] - 1 < nums[j]) {
              }
              decrements[j]--;
              if (curr[j])
            }
          }
        }
        curr = {-1, -1};
      } else {
        if (curr.front() == -1) {
          curr = {i, i};
        } else {
          curr[1]++;
        }
      }
    }
    return result;
  }
};
