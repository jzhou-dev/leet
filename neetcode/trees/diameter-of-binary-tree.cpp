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
    int diameterOfBinaryTree(TreeNode* root) {
        int len = 0;
        helper(root, len);
        return len;
    }
    int helper(TreeNode* root, int& len) {
        if (root == nullptr) {
            return 0;
        }
        int left = helper(root->left, len);
        int right = helper(root->right, len);
        if (left + right > len) {
            len = left+right;
        }
        return 1 + max(left, right);
    }
};
