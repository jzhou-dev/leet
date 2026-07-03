#include "../leet.h"

struct TrieNode {
  TrieNode *children[26];
  bool EOW;
  std::vector<std::string> words;
  int num_children = 0;
  TrieNode() {
    for (int i = 0; i < 26; ++i) {
      children[i] = nullptr;
    }
    EOW = false;
    words = {};
  }
};
class Solution {
public:
  std::vector<std::string> result;
  std::vector<std::string> findWords(std::vector<std::vector<char>> &board,
                                     std::vector<std::string> &words) {
    TrieNode *root = new TrieNode();
    std::vector<std::vector<bool>> used(
        board.size(), std::vector<bool>(board[0].size(), false));
    for (int i = 0; i < words.size(); ++i) {
      TrieNode *curr = root;
      for (int j = 0; j < words[i].size(); ++j) {
        if (!curr->children[words[i][j] - 'a']) {
          curr->children[words[i][j] - 'a'] = new TrieNode();
          curr->num_children++;
        }
        curr = curr->children[words[i][j] - 'a'];
      }
      curr->words.push_back(words[i]);
      curr->EOW = true;
    }
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (root->children[board[i][j] - 'a']) {
          search(board, used, root, i, j);
        }
      }
    }
    return result;
  }
  void search(std::vector<std::vector<char>> &board,
              std::vector<std::vector<bool>> &used, TrieNode *root, int i,
              int j) {
    if (root->EOW) {
      result.insert(result.end(), root->words.begin(), root->words.end());
      root->EOW = false;
    }
    if (!root || i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
        used[i][j]) {
      return;
    }
    used[i][j] = true;
    if (root->children[board[i][j] - 'a']) {
      search(board, used, root->children[board[i][j] - 'a'], i + 1, j);
      search(board, used, root->children[board[i][j] - 'a'], i, j + 1);
      search(board, used, root->children[board[i][j] - 'a'], i - 1, j);
      search(board, used, root->children[board[i][j] - 'a'], i, j - 1);
      if (root->children[board[i][j] - 'a']->num_children == 0) {
        root->num_children--;
        delete (root->children[board[i][j] - 'a']);
        root->children[board[i][j] - 'a'] = nullptr;
      }
    }
    used[i][j] = false;
  }
};
