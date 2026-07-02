#include "../leet.h"

class Solution {
public:
  int ladderLength(std::string beginWord, std::string endWord,
                   std::vector<std::string> &wordList) {
    std::unordered_map<std::string, int> min_words;
    std::queue<std::string> queue;
    std::unordered_set<std::string> words(wordList.begin(), wordList.end());
    queue.push(beginWord);
    min_words[beginWord] = 1;
    while (!queue.empty()) {
      std::string currWord = queue.front();
      queue.pop();
      if (currWord == endWord) {
        return min_words[currWord];
      }
      for (int i = 0; i < currWord.size(); i++) {
        for (auto c : "abcdefghijklmnopqrstuvwxyz") {
          std::string temp = currWord;
          temp[i] = c;
          if (words.count(temp) && min_words[temp] == 0 && temp != beginWord) {
            queue.push(temp);
            min_words[temp] = min_words[currWord] + 1;
          }
        }
      }
    }
    return 0;
  }
};
