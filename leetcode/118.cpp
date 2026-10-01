#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    result.push_back({1});
    for (int i = 1; i < numRows; ++i) {
      vector<int> row = {1};
      for (int j = 1; j < result.back().size(); ++j) {
        row.push_back(result.back()[j - 1] + result.back()[j]);
      }
      row.push_back(1);
      result.push_back(row);
    }
    return result;
  }
};
