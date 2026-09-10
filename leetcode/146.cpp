using namespace std;
#include <unordered_map>

struct Node {
  int key;
  int val;
  Node *next;
  Node *prev;
  Node() : key(), val(), next(), prev() {};
  Node(int k, int v) : key(k), val(v), next(), prev() {};
};

class LRUCache {
public:
  unordered_map<int, Node *> cache;
  Node *head = new Node();
  Node *tail = new Node();
  int capacity;
  int size = 0;
  LRUCache(int _capacity) {
    head->next = tail;
    tail->prev = head;
    capacity = _capacity;
  }
  int get(int key) {
    if (!cache.count(key))
      return -1;
    Node *curr = cache[key];
    if (curr->next != tail) {
      if (curr->prev && curr->next) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
      }
      curr->prev = tail->prev;
      curr->next = tail;
      tail->prev->next = curr;
      tail->prev = curr;
    }
    return curr->val;
  }
  void put(int key, int value) {
    if (cache.count(key)) {
      cache[key]->val = value;
    } else {
      if (cache.size() >= capacity) {
        cache.erase(head->next->key);
        head->next = head->next->next;
        head->next->prev = head;
      }
      cache[key] = new Node(key, value);
    }
    get(key);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
