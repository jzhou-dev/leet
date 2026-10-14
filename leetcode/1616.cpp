using namespace std;
#include <string>

class Solution {
public:
  bool checkPalindromeFormation(string a, string b) {
    return checkPalindrome(a, b) || checkPalindrome(b, a);
  }
  bool checkPalindrome(string &a, string &b) {
    int l = 0;
    int r = a.size() - 1;
    while (l <= r && a[l] == b[r]) {
      l++;
      r--;
    }
    return checkPalindrome(a, l, r) || checkPalindrome(b, l, r);
  }
  bool checkPalindrome(string &a, int l, int r) {
    while (l <= r) {
      if (a[l++] != a[r--]) {
        return false;
      }
    }
    return true;
  }
};
