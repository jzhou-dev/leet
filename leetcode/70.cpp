#include <vector>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2) {
      return n;
    }
    int temp1 = 1;
    int temp2 = 1;
    int curr = 2;
    for (int i = 2; i <= n; ++i) {
      int temp_curr = curr;
      curr = temp1 + temp2;
      swap(temp1, temp2);
      temp2 = curr;
    }
    return curr;
  }
};
