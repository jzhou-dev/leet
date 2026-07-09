#include "../leet.h"

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    int carry = 0;
    int aIndex = a.size() - 1;
    int bIndex = b.size() - 1;
    std::string result = "";
    while (aIndex >= 0 || bIndex >= 0) {
      int curr = 0;
      if (aIndex >= 0 && a[aIndex] == '1') {
        curr++;
      }
      if (bIndex >= 0 && b[bIndex] == '1') {
        curr++;
      }
      curr += carry;
      carry = 0;
      result += std::to_string(curr % 2);
      if (curr >= 2)
        carry++;
      aIndex--;
      bIndex--;
    }
    if (carry) {
      result.push_back('1');
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};
