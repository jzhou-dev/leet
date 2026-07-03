#include <unordered_set>

class Trie {
public:
  std::unordered_set<std::string> words;
  Trie() {}
  void insert(std::string word) { words.insert(word); }
  bool search(std::string word) { return words.count(word); }
  bool startsWith(std::string prefix) {
    for (auto word : words) {
      if (word.size() >= prefix.size() &&
          word.substr(0, prefix.size()) == prefix) {
        return true;
      }
    }
    return false;
  }
};
