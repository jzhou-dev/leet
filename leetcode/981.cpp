#include "../leet.h"

class TimeMap {
public:
  std::unordered_map<std::string, std::vector<std::pair<int, std::string>>>
      store;
  void set(std::string key, std::string value, int timestamp) {
    store[key].push_back({timestamp, value});
  }
  std::string get(std::string key, int timestamp) {
    std::string result = "";
    int l = 0;
    int r = store[key].size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (store[key][mid].first == timestamp) {
        return store[key][mid].second;
      } else if (store[key][mid].first < timestamp) {
        result = store[key][mid].second;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return result;
  }
};
