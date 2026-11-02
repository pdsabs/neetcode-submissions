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
    bool isBalanced(TreeNode* root) {
        return check(root).first;
    }

    pair<bool, int> check(TreeNode* node) {
        if (!node) return {true, 0};
        
        auto [leftBal, leftH] = check(node->left);
        auto [rightBal, rightH] = check(node->right);
        
        bool balanced = leftBal && rightBal && abs(leftH - rightH) <= 1;
        return {balanced, 1 + max(leftH, rightH)};
    }
};
