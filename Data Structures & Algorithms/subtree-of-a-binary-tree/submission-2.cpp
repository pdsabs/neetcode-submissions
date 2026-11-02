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
    bool checkSubtree(TreeNode* root, TreeNode* sub) {
        if (!root && !sub) return true; 
        if (!root || !sub || root->val != sub->val) return false;
        return checkSubtree(root->left, sub->left) && checkSubtree(root->right, sub->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        if (root->val == subRoot->val) {
            if(checkSubtree(root, subRoot)) return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
