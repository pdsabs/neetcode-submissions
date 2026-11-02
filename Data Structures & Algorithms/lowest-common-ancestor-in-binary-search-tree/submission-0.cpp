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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto pPath = dfs(root, p);
        auto qPath = dfs(root, q);

        auto pIt = pPath.begin();
        auto qIt = qPath.begin();

        TreeNode* lca = nullptr;
        while(pIt != pPath.end() && qIt != qPath.end()) {
            if (*pIt == *qIt) lca = *pIt;
            pIt++;
            qIt++;
        }

        return lca;    
    }

    vector<TreeNode*> dfs(TreeNode* root, TreeNode* target) {
        stack<pair<TreeNode*, vector<TreeNode*>>> st;
        st.push({root, {}});

        while (!st.empty()) {
            auto [curr, path] = st.top();
            st.pop();

            path.push_back(curr);

            if (curr->val == target->val) return path;

            if (curr->right) st.push({curr->right, path});
            if (curr->left) st.push({curr->left, path});
        }

        return {};
    }
};
