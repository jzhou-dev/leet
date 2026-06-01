#include "leet.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        if (helper(root, subRoot)) {
            return true;
        } 
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool helper(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true;
        } else if (!root || !subRoot) {
            return false;
        } else if (root->val != subRoot->val) {
            return false;
        } else {
            return helper(root->left, subRoot->left) && helper(root->right, subRoot->right);
        }
    }
};
