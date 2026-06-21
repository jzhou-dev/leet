#include "leet.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> row_set;
        vector<unordered_set<int>> col_sets(9);
        vector<vector<unordered_set<int>>> box_sets(3, vector<unordered_set<int>>(3));
        for (int i = 0; i < board.size(); i++) {
          for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != '.') {
              int el = board[i][j];
              if (row_set.count(el) || col_sets[j].count(el) || box_sets[i/3][j/3].count(el)) {
                return false;
              }
              row_set.insert(el);
              col_sets[j].insert(el);
              box_sets[i/3][j/3].insert(el);
            }
          }
          row_set.clear();
        }
        return true;
    }
};
