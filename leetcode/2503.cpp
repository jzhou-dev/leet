using namespace std;
#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
public:
  vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
    unordered_map<int, int> original;
    for (int i = 0; i < queries.size(); ++i) {
      original[queries[i]] = i;
    }
    sort(queries.begin(), queries.end());
    vector<int> answers(queries.size());
    int curr_idx = 0;
    int curr_points = 0;
    queue<vector<int>> q;
    q.push({0, 0, grid[0][0]});
    grid[0][0] = -1;
    while (!q.empty()) {
      int size = q.size();
      int num_points = 0;
      for (int i = 0; i < size; ++i) {
        int row = q.front()[0], col = q.front()[1], num = q.front()[2];
        q.pop();
        if (num < queries[curr_idx]) {
          num_points++;
          curr_points++;
          for (auto direction : directions) {
            int new_row = row + direction.first;
            int new_col = col + direction.second;
            if (new_row < 0 || new_row >= grid.size() || new_col < 0 ||
                new_col >= grid[0].size()) {
              continue;
            }
            if (grid[row + direction.first][col + direction.second] != -1) {
              q.push({row + direction.first, col + direction.second,
                      grid[row + direction.first][col + direction.second]});
              grid[row + direction.first][col + direction.second] = -1;
            }
          }
        } else {
          q.push({row, col, num});
        }
      }
      if (num_points == 0) {
        answers[original[queries[curr_idx]]] = curr_points;
        curr_idx++;
        if (curr_idx >= queries.size()) {
          break;
        }
      }
    }
    if (curr_idx != queries.size()) {
      for (int i = curr_idx; i < queries.size(); ++i) {
        answers[original[queries[i]]] = curr_points;
      }
    }
    return answers;
  }
};
