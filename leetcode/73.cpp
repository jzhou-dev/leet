#include "leet.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      vector<bool> zrows(matrix.size());
      vector<bool> zcols(matrix[0].size());
      for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
          if (matrix[i][j]==0) {
            zrows[i] = true;
            zcols[j] = true;
          }
        }
      }
      for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
          if (zrows[i] || zcols[j]) {
            matrix[i][j] = 0;
          }
        }
      }
    }
};
