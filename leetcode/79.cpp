#include "../leet.h"

class Solution {
public:
  bool exist(std::vector<std::vector<char>> &board, std::string word) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == word[0]) {
          std::string curr = "";
          if (exist(board, word, curr, i, j)) {
            return true;
          }
        }
      }
    }
    return false;
  }
  bool exist(std::vector<std::vector<char>> &board, std::string &word,
             std::string &curr, int i, int j) {
    if (curr.size() == word.size()) {
      if (curr == word) {
        return true;
      }
      return false;
    }
    if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 ||
        board[i][j] == '#') {
      return false;
    }
    if (curr.size() > 0 && curr.back() != word[curr.size() - 1]) {
      return false;
    }
    char c = board[i][j];
    board[i][j] = '#';
    curr.push_back(c);
    bool result = exist(board, word, curr, i + 1, j) ||
                  exist(board, word, curr, i, j + 1) ||
                  exist(board, word, curr, i - 1, j) ||
                  exist(board, word, curr, i, j - 1);
    board[i][j] = c;
    curr.pop_back();
    return result;
  }
};
