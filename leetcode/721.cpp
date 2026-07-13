#include "../leet.h"

class Solution {
public:
  std::vector<std::vector<std::string>>
  accountsMerge(std::vector<std::vector<std::string>> &accounts) {
    std::unordered_map<std::string, std::string> parents;
    std::unordered_map<std::string, std::string> names;
    std::unordered_map<std::string, std::set<std::string>> merged;
    std::vector<std::vector<std::string>> result;
    for (auto account : accounts) {
      for (int i = 1; i < account.size(); ++i) {
        parents[account[i]] = account[i];
        names[account[i]] = account[0];
      }
    }
    for (auto account : accounts) {
      std::string root = find(account[1], parents);
      for (int i = 2; i < account.size(); ++i) {
        parents[find(account[i], parents)] = root;
      }
    }
    for (auto parent : parents) {
      merged[find(parent.first, parents)].insert(parent.first);
    }
    for (auto i : merged) {
      std::vector<std::string> account;
      account.push_back(names[i.first]);
      account.insert(account.end(), i.second.begin(), i.second.end());
      result.push_back(account);
    }
    return result;
  }

private:
  std::string find(std::string root,
                   std::unordered_map<std::string, std::string> &parents) {
    if (parents[root] == root) {
      return root;
    } else {
      return find(parents[root], parents);
    }
  }
};
