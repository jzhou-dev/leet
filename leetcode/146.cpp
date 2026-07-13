#include <unordered_map>

struct Node {
  int key;
  int value;
  Node *next;
  Node *prev;
  Node() {
    key = 0;
    value = 0;
    next = nullptr;
    prev = nullptr;
  }
  Node(int _key, int _val) {
    key = _key;
    value = _val;
    next = nullptr;
    prev = nullptr;
  }
};

class LRUCache {
public:
  Node *head;
  Node *tail;
  std::unordered_map<int, Node *> nodes;
  int capacity = 0;
  LRUCache(int capacity) {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
    this->capacity = capacity;
  }

  int get(int key) {
    if (!nodes.count(key)) {
      return -1;
    }
    if (tail->prev == nodes[key]) {
      return nodes[key]->value;
    }
    if (nodes[key]->prev && nodes[key]->next) {
      nodes[key]->prev->next = nodes[key]->next;
      nodes[key]->next->prev = nodes[key]->prev;
    }
    nodes[key]->prev = tail->prev;
    nodes[key]->next = tail;
    tail->prev->next = nodes[key];
    tail->prev = nodes[key];
    return nodes[key]->value;
  }

  void put(int key, int value) {
    if (nodes.count(key)) {
      nodes[key]->value = value;
      get(key);
      return;
    }
    if (nodes.size() >= capacity) {
      nodes.erase(head->next->key);
      head = head->next;
      head->prev = nullptr;
    }
    nodes.insert({key, new Node(key, value)});
    get(key);
  }
};
