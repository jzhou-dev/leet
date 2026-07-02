#include "../leet.h"

class Solution {
public:
  void solve(std::vector<std::vector<char>> &board) {
    for (int i = 0; i < board.size(); ++i) {
      if (board[i][0] == 'O') {
        solve(board, i, 0);
      }
      if (board[i][board[0].size() - 1] == 'O') {
        solve(board, i, board[0].size() - 1);
      }
    }
    for (int j = 0; j < board[0].size(); ++j) {
      if (board[0][j] == 'O') {
        solve(board, 0, j);
      }
      if (board[board.size() - 1][j] == 'O') {
        solve(board, board.size() - 1, j);
      }
    }
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == '*') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
  void solve(std::vector<std::vector<char>> &board, int i, int j) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
        board[i][j] == '*' || board[i][j] == 'X') {
      return;
    }
    board[i][j] = '*';
    solve(board, i + 1, j);
    solve(board, i - 1, j);
    solve(board, i, j + 1);
    solve(board, i, j - 1);
  }
};
