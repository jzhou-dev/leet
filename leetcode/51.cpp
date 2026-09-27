#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> result;
  vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    solveNQueens(n, board, 0);
    return result;
  }
  void solveNQueens(int n, vector<string> &board, int row) {
    if (n == 0) {
      result.push_back(board);
      return;
    }
    for (int i = 0; i < board.size(); ++i) {
      if (validPos(board, row, i)) {
        board[row][i] = 'Q';
        solveNQueens(n - 1, board, row + 1);
        board[row][i] = '.';
      }
    }
  }
  bool validPos(vector<string> &board, int i, int j) {
    for (int x = 0; x < board.size(); ++x) {
      if (board[x][j] == 'Q' && x != i) {
        return false;
      }
    }
    int row = i - 1;
    int col = j - 1;
    while (row >= 0 && col >= 0) {
      if (board[row][col] == 'Q') {
        return false;
      }
      row--, col--;
    }
    row = i - 1;
    col = j + 1;
    while (row >= 0 && col < board.size()) {
      if (board[row][col] == 'Q') {
        return false;
      }
      row--, col++;
    }
    return true;
  }
};
