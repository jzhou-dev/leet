#include <unordered_map>
struct Node {
  int key;
  int val;
  Node *prev;
  Node *next;
  Node() {
    key = 0;
    val = 0;
    prev = nullptr;
    next = nullptr;
  }
  Node(int x, int y) {
    key = x;
    val = y;
    prev = nullptr;
    next = nullptr;
  }
};

class LRUCache {
public:
  std::unordered_map<int, Node *> store;
  int size = 0;
  int capacity = 0;
  Node *head = new Node();
  Node *tail = new Node();

  LRUCache(int capacity) {
    head->next = tail;
    tail->prev = head;
    this->capacity = capacity;
  }

  int get(int key) {
    if (store.count(key)) {
      if (store[key] != tail->prev) {
        if (store[key]->prev && store[key]->next) {
          store[key]->prev->next = store[key]->next;
          store[key]->next->prev = store[key]->prev;
        }
        tail->prev->next = store[key];
        store[key]->prev = tail->prev;
        store[key]->next = tail;
        tail->prev = store[key];
      }
      return store[key]->val;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    if (store.count(key)) {
      store[key]->val = value;
      get(key);
    } else {
      if (size == capacity) {
        store.erase(head->next->key);
        head = head->next;
        head->prev = nullptr;
        size--;
      }
      Node *newNode = new Node(key, value);
      store.insert({key, newNode});
      get(key);
      size++;
    }
  }
};
