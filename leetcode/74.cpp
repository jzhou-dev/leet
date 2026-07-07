#include "../leet.h"

class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    int left = 0;
    int right = matrix.size() * matrix[0].size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      int row = mid / matrix.size();
      int col = mid % matrix[0].size();
      if (row < 0 || row >= matrix.size() || col < 0 ||
          col >= matrix[0].size()) {
        return false;
      }
      if (matrix[row][col] == target) {
        return true;
      } else if (matrix[row][col] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
};
