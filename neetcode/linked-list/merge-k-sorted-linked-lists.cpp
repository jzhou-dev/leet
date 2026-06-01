#include "leet.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while (l1 || l2) {
            if (!l1) {
                curr->next = l2;
                break;
            } else if (!l2) {
                curr->next = l1;
                break;
            } else {
                if (l1->val < l2->val) {
                    curr->next = l1;
                    l1 = l1->next;
                } else {
                    curr->next = l2;
                    l2 = l2->next;
                }
                curr = curr->next;
            }
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists = {};
            for (int i = 0; i < lists.size(); i+=2) {
                if (i+1 < lists.size()) {
                    mergedLists.push_back(mergeTwoLists(lists[i], lists[i+1]));
                } else {
                    mergedLists.push_back(lists[i]);
                }
            }
            lists = mergedLists;
        }
        return lists.size() >= 1 ? lists[0] : nullptr;
    }
};
