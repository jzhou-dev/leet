#include "../leet.h"

class Solution {
public:
  std::unordered_map<std::string, std::string> parents;
  std::unordered_map<std::string, std::string> names;
  std::unordered_map<std::string, std::set<std::string>> Union;
  std::vector<std::vector<std::string>>
  accountsMerge(std::vector<std::vector<std::string>> &accounts) {
    std::vector<std::vector<std::string>> result;
    for (auto account : accounts) {
      names[account[1]] = account[0];
      for (int i = 1; i < account.size(); ++i) {
        parents[account[i]] = {account[1]};
      }
    }
    for (auto account : accounts) {
      std::string root = find(account[1]);
      for (int i = 2; i < account.size(); ++i) {
        parents[find(account[i])] = root;
      }
    }
    for (auto account : accounts) {
      for (int i = 1; i < account.size(); ++i) {
        Union[find(account[i])].insert(account[i]);
      }
    }
    for (auto account : Union) {
      std::vector<std::string> emails(account.second.begin(),
                                      account.second.end());
      result.push_back({names[account.first]});
      result.back().insert(result.back().end(), emails.begin(), emails.end());
    }
    return result;
  }

private:
  std::string find(std::string root) {
    return parents[root] == root ? root : parents[root] = find(parents[root]);
  }
};
