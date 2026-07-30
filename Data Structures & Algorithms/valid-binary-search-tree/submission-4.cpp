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
    bool isValidBST(TreeNode* root) {
        stack<tuple<TreeNode*, int, int>> dfsstack;
        dfsstack.push({root, INT_MIN, INT_MAX});

        while (!dfsstack.empty()) {
            auto [node, left, right] = dfsstack.top();
            dfsstack.pop();

            if (!node) continue;
            if (node->val <= left || node->val >= right) return false;

            dfsstack.push({node->left, left, node->val});
            dfsstack.push({node->right, node->val, right});
        }

        return true;
    }
};

// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         return valid(root, INT_MIN, INT_MAX);
//     }

//     bool valid (TreeNode* root, int left, int right) {
//         if (!root) return true;

//         if (root->val <= left || root->val >= right) {
//             return false;
//         }
        
//         return valid(root->left, left, root->val) && valid(root->right, root->val, right);
//     }
// };