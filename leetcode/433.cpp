#include "../leet.h"

class Solution {
public:
  int minMutation(std::string startGene, std::string endGene,
                  std::vector<std::string> &bank) {
    std::unordered_map<std::string, int> min_mutations;
    std::queue<std::string> queue;
    std::unordered_set<std::string> mutations(bank.begin(), bank.end());
    min_mutations[startGene] = 0;
    queue.push(startGene);
    while (!queue.empty()) {
      std::string curr = queue.front();
      queue.pop();
      if (curr == endGene) {
        return min_mutations[curr];
      }
      for (int i = 0; i < curr.size(); i++) {
        for (char c : "ACGT") {
          std::string temp = curr;
          temp[i] = c;
          if (mutations.count(temp) && min_mutations[temp] == 0 &&
              temp != startGene) {
            queue.push(temp);
            min_mutations[temp] = min_mutations[curr] + 1;
          }
        }
      }
    }
    return -1;
  }
};
