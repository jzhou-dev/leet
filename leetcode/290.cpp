class Solution {
public:
    bool wordPattern(string pattern, string s) {
      std::unordered_map<string, char> s_store;
      std::unordered_map<char, string> pattern_store;
      std::string word;
      std::stringstream ss(s);
      int index = 0;
      while (std::getline(ss, word, ' ')) {
        if (!s_store.count(word)) {
          s_store[word] = pattern[index];
        }
        if (!pattern_store.count(pattern[index])) {
          pattern_store[pattern[index]] = word;
        }
        if (s_store[word] != pattern[index] || pattern_store[pattern[index]] != word) {
          return false;
        }
        index++;
      }
      return index==pattern.size();
    }
};
