#include <unordered_map>

struct Node {
  int key;
  int value;
  Node *next;
  Node *prev;
  Node() : key(0), value(0) {};
  Node(int _key, int _value) : key(_key), value(_value) {};
};
class LRUCache {
public:
  std::unordered_map<int, Node *> cache;
  Node *head;
  Node *tail;
  int capacity;
  LRUCache(int capacity) {
    this->capacity = capacity;
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (!cache.count(key)) {
      return -1;
    }
    Node *curr = cache[key];
    if (tail->prev != curr) {
      if (curr->next && curr->prev) {
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
      }
      curr->prev = tail->prev;
      curr->next = tail;
      tail->prev->next = curr;
      tail->prev = curr;
    }
    return curr->value;
  }

  void put(int key, int value) {
    if (cache.size() >= capacity) {
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
