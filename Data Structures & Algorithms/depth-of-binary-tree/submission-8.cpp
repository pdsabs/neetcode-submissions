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
        stack<pair<TreeNode*, int>> depthStack;
        depthStack.push({root, 1});
        int res = 0;

        while (!depthStack.empty()) {
            pair<TreeNode*,int> curr = depthStack.top();
            depthStack.pop();
            TreeNode* node = curr.first;
            int depth = curr.second;

            if (node != nullptr) {
                res = max(depth, res);
                depthStack.push({node->left, depth+1});
                depthStack.push({node->right, depth+1});
            }
        }
        return res;
    }
};
