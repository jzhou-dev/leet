#include "../leet.h"

struct TrieNode {
  bool EOW;
  std::unordered_map<char, TrieNode *> children;
  TrieNode() { EOW = false; }
};

class WordDictionary {
public:
  TrieNode *head;
  WordDictionary() { head = new TrieNode(); }
  void addWord(std::string word) {
    TrieNode *curr = head;
    for (char c : word) {
      if (!curr->children[c - 'a']) {
        curr->children[c - 'a'] = new TrieNode();
      }
      curr = curr->children[c - 'a'];
    }
    curr->EOW = true;
  }
  bool search(std::string word) { return search(word, 0, head); }
  bool search(std::string &word, int pos, TrieNode *curr) {
    if (pos == word.size()) {
      return curr->EOW;
    }
    if (word[pos] == '.') {
      for (int i = 0; i < curr->children.size(); i++) {
        if (curr->children[i]) {
          if (search(word, pos + 1, curr->children[i])) {
            return true;
          }
        }
      }
    } else {
      if (!curr->children[word[pos] - 'a']) {
        return false;
      }
      return search(word, pos + 1, curr->children[word[pos] - 'a']);
    }
    return false;
  }
};
