class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      std::unordered_map<char, int> freq;
      for (const auto& i : ransomNote) {
        freq[i]++;
      }
      int need = freq.size();
      for (const auto& i : magazine) {
        freq[i]--;
        if (freq[i] == 0) {
          need--;
        }
        if (need==0) {
          return true;
        }
      }
      return false;
    }
};
