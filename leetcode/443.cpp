#include "../leet.h"

class Solution {
public:
  int compress(std::vector<char> &chars) {
    int read = 0;
    int write = 0;
    while (read < chars.size()) {
      char c = chars[read];
      int len = 0;
      while (read < chars.size() && chars[read] == c) {
        read++;
        len++;
      }
      chars[write++] = c;
      if (len > 1) {
        for (auto digit : std::to_string(len)) {
          chars[write++] = digit;
        }
      }
    }
    return write;
  }
};
