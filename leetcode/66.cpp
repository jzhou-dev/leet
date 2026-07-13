#include "../leet.h"

class Solution {
public:
  std::vector<int> plusOne(std::vector<int> &digits) {
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      int curr = digits[i] + carry;
      digits[i] = curr % 10;
      carry = curr / 10;
    }
    if (carry)
      digits.insert(digits.begin(), carry);
    return digits;
  }
};
