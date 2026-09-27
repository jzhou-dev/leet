#include <vector>
using namespace std;

class Solution {
public:
  vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == word[0] && exist(board, word, 0, {i, j})) {
          return true;
        }
      }
    }
    return false;
  }
  bool exist(vector<vector<char>> &board, string &word, int i,
             pair<int, int> b_i) {
    if (i == word.size()) {
      return true;
    }
    if (b_i.first >= board.size() || b_i.first < 0 ||
        b_i.second >= board[0].size() || b_i.second < 0 ||
        board[b_i.first][b_i.second] == '.' ||
        board[b_i.first][b_i.second] != word[i]) {
      return false;
    }
    char temp = board[b_i.first][b_i.second];
    board[b_i.first][b_i.second] = '.';
    bool result = false;
    for (auto direction : directions) {
      result = result || exist(board, word, i + 1,
                               {b_i.first + direction.first,
                                b_i.second + direction.second});
    }
    board[b_i.first][b_i.second] = temp;
    return result;
  }
};
