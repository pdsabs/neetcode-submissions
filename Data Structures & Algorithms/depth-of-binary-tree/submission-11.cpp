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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*,int>> depq;
        depq.push({root, 1});
        int maxdep = 0;
        while (!depq.empty()) {
            pair<TreeNode*,int> curr = depq.front();
            depq.pop();

            TreeNode* node = curr.first;
            int depth = curr.second;

            if (node) {
                maxdep = max(maxdep, depth);
                if (node->left) depq.push({node->left, depth+1});
                if (node->right) depq.push({node->right, depth+1});
            }
        }

        return maxdep;
    }
};
