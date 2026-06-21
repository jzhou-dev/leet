#include "leet.h"

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        update(board, 0);
    }
    void update(vector<vector<int>>& board, int index) {
      if (index > board.size() * board[0].size()-1) {
        return;
      }
      int row = index/board[0].size();
      int col = index % board[0].size();
      int neighbors = find_neighbors(board, row, col);
      update(board, index+1);
      if ((board[row][col] && (neighbors < 2 || neighbors > 3)) || (!board[row][col] && neighbors == 3)) {
        board[row][col] = !board[row][col];
      }
    }
    int find_neighbors(vector<vector<int>>& board, int row, int col) {
      int neighbors = 0;
      if (row-1 >= 0 && board[row-1][col]) {
        neighbors++;
      }
      if (row+1 < board.size() && board[row+1][col]) {
        neighbors++;
      }
      if (col-1 >= 0 && board[row][col-1]) {
        neighbors++;
      }
      if (col+1 < board[0].size() && board[row][col+1]) {
        neighbors++;
      }
      if (row-1>=0 && col-1 >= 0 && board[row-1][col-1]) {
        neighbors++;
      }
      if (row-1>=0 &&col+1 < board[0].size() && board[row-1][col+1]) {
        neighbors++;
      }
      if (row+1<board.size() &&col-1 >= 0 && board[row+1][col-1]) {
        neighbors++;
      }
      if (row+1<board.size() && col+1 < board[0].size() && board[row+1][col+1]) {
        neighbors++;
      }
      return neighbors;
    }
};
