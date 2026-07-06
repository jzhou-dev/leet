#include "../leet.h"

class Solution {
public:
  int result = 0;
  int totalNQueens(int n) {
    std::vector<std::vector<int>> board(n, std::vector(n, 0));
    totalNQueens(board, 0, n);
    return result;
  }
  void totalNQueens(std::vector<std::vector<int>> &board, int row, int n) {
    if (n == 0) {
      result++;
      return;
    }
    for (int i = 0; i < board.size(); ++i) {
      if (validQueen(board, row, i)) {
        board[row][i] = 1;
        totalNQueens(board, row + 1, n - 1);
        board[row][i] = 0;
      }
    }
  }
  bool validQueen(std::vector<std::vector<int>> &board, int i, int j) {
    // check col
    for (int x = 0; x < board.size(); x++) {
      if (board[x][j] && x != i) {
        return false;
      }
    }
    int row = i - 1;
    int col = j - 1;
    while (row >= 0 && col >= 0) {
      if (board[row][col]) {
        return false;
      }
      row--;
      col--;
    }
    row = i - 1;
    col = j + 1;
    while (row >= 0 && col < board.size()) {
      if (board[row][col]) {
        return false;
      }
      row--;
      col++;
    }
    return true;
  }
};
