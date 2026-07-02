#include "../leet.h"

class Solution {
public:
  int snakesAndLadders(std::vector<std::vector<int>> &board) {
    std::vector<int> min_turns(std::pow(board.size(), 2), 0);
    std::queue<int> queue;
    queue.push(1);
    while (!queue.empty()) {
      int pos = queue.front();
      queue.pop();
      for (int i = 1; i <= 6; i++) {
        int new_pos = pos + i;
        if (new_pos > std::pow(board.size(), 2)) {
          break;
        }
        auto [row, col] = convert(new_pos, board.size());
        if (board[row][col] != -1) {
          new_pos = board[row][col];
        }
        if (min_turns[new_pos - 1] == 0 && new_pos != 1) {
          queue.push(new_pos);
          min_turns[new_pos - 1] = min_turns[pos - 1] + 1;
        }
      }
    }
    return min_turns.back() == 0 ? -1 : min_turns.back();
  }
  std::pair<int, int> convert(int pos, int n) {
    int row = n - (pos - 1) / n - 1;
    int col = (pos - 1) % n;
    if ((n - 1 - row) % 2 == 1) {
      col = n - 1 - col;
    }
    return {row, col};
  }
};
