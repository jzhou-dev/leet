#include "../leet.h"

class Solution {
public:
  std::string simplifyPath(std::string path) {
    std::vector<std::string> stack;
    std::string result;
    int i = 0;
    while (i < path.size()) {
      std::string curr = "";
      if (path[i] == '/') {
        i++;
      } else {
        while (path[i] != '/' && i < path.size()) {
          curr.push_back(path[i]);
          i++;
        }
        if (curr == "..") {
          if (!stack.empty()) {
            stack.pop_back();
          }
        } else if (curr != ".") {
          stack.push_back(curr);
        }
      }
    }
    for (auto s : stack) {
      result += "/" + s;
    }
    if (result == "") {
      result = "/";
    }
    return result;
  }
};
