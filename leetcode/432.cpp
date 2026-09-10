using namespace std;
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

struct Node {
  string key;
  int count;
  Node *next;
  Node *prev;
  Node() : key(), count(), next(), prev() {};
  Node(string k) : key(k), count(), next(), prev() {};
};

class AllOne {
public:
  unordered_map<string, int> keys;
  map<int, unordered_set<string>> freqs;
  AllOne() {}
  void inc(string key) {
    int before = keys[key];
    int after = ++keys[key];
    if (before != 0) {
      freqs[before].erase(key);
      if (freqs[before].empty()) {
        freqs.erase(before);
      }
    }
    freqs[after].insert(key);
    for (auto i : keys) {
      cout << i.first << ": " << i.second << endl;
    }
    cout << endl;
    for (auto i : freqs) {
      cout << i.first << ": ";
      for (auto &j : i.second) {
        cout << j << " ";
      }
    }
    cout << endl;
    cout << endl;
  }

  void dec(string key) {
    int before = keys[key];
    int after = --keys[key];
    freqs[before].erase(key);
    if (freqs[before].empty()) {
      freqs.erase(before);
    }
    if (after == 0) {
      keys.erase(key);
    } else {
      freqs[after].insert(key);
    }
    for (auto i : keys) {
      cout << i.first << ": " << i.second << endl;
    }
    cout << endl;
    for (auto i : freqs) {
      cout << i.first << ": ";
      for (auto &j : i.second) {
        cout << j << " ";
      }
    }
    cout << endl;
    cout << endl;
  }

  string getMaxKey() {
    return freqs.empty() ? "" : *freqs.begin()->second.begin();
  }

  string getMinKey() {
    return freqs.empty() ? "" : *freqs.rbegin()->second.begin();
  }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
