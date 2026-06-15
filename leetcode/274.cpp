#include "leet.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
      vector<int> freq(citations.size()+1, 0);
      for (int i = 0; i < citations.size(); i++) {
        if (citations[i] > citations.size()) {
          freq[citations.size()]++;
        } else {
          freq[citations[i]]++;
        }
      }
      int total = 0;
      for (int i = freq.size()-1; i>0; i--) {
        total += freq[i];
        if (total >= i) {
          return i;
        }
      }
      return 0;
    }
};
