#include "leet.h"

struct Node {
    Node* nodes[26];
    bool EOW;
    Node() {
        for (int i = 0; i < 26; i++) {
            nodes[i] = nullptr;
        }
        EOW = false;
    }
};
class Solution {
public:
    Node* head = new Node();
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            Node* curr = head;
            for (int j = 0; j < words[i].size(); j++) {
                if (!curr->nodes[words[i][j] - 'a']) {
                    curr->nodes[words[i][j] - 'a'] = new Node();
                }
                curr = curr->nodes[words[i][j] - 'a'];
            }
            curr->EOW = true;
        }
        
    }
};
