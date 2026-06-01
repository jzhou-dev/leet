#include "leet.h"

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int size = 0;
    int capacity = 0;
    unordered_map<int, Node*> cache;
    Node* tail;
    Node* head;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        cache = {};
    }
    
    int get(int key) {
        if (cache.count(key)) {
            if (cache[key] != tail->prev) {
                if (cache[key]->prev) {
                    cache[key]->prev->next = cache[key]->next;
                    cache[key]->next->prev = cache[key]->prev;
                }
                cache[key]->prev = tail->prev;
                cache[key]->prev->next = cache[key];
                cache[key]->next = tail;
                tail->prev = cache[key];
            }
            return cache[key]->val;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            cache[key]->val = value;
            get(key);
        } else {
            if (size == capacity) {
                cache.erase(head->next->key);
                head->next = head->next->next;
                head->next->prev = head;

                size--;
            } 
            size++;
            Node* node = new Node(key, value);
            node->prev = tail->prev;
            node->prev->next = node;
            node->next = tail;
            tail->prev = node;
            cache[key] = node;
        }
    }
};
