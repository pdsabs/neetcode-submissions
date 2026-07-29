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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> dfsstack;
        dfsstack.push({p, q});

        while (!dfsstack.empty()) {
            auto [p, q] = dfsstack.top();
            dfsstack.pop();

            if (!p && !q) continue;
            if (!p && q) return false;
            if (p && !q) return false;
            if (p->val != q->val) return false;
            dfsstack.push({p->left, q->left});
            dfsstack.push({p->right, q->right});
        }

        return true;
    }
};
